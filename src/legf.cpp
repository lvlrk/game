#include <iostream>
#include <fstream>
#include <fmt/core.h>
#include <zlib.h>
#include "legf.h"
#include "lzss.h"

void Legf::Entry::FromFile(const std::string& filename, int resType) {
    this->filename = filename;
    this->resType = resType;

    std::ifstream inf(filename, std::ios::ate);
    if(!inf.is_open()) {
        data = std::vector<char>(0);
        return;
    }

    dataSize = inf.tellg();
    inf.seekg(0);

    data.resize(dataSize);

    inf.read(reinterpret_cast<char*>(&data[0]), dataSize);

    inf.close();
}

int Legf::Entry::Compress(int compType) {
    this->compType = compType;

    if(compType == COMP_NONE) return 0;
    else {
        if(!dataSize || !data.size()) return 1;
        isCompressed = true;
        compressedData.resize(dataSize);

        if(compType == COMP_LZSS) {
            lzss_compress(reinterpret_cast<u8*>(&data[0]), dataSize, reinterpret_cast<u8*>(&compressedData[0]), dataSize);
        } else if(compType == COMP_ZLIB) {
            compressedDataSize = dataSize;
            int zlibRet = compress(reinterpret_cast<Bytef*>(&compressedData[0]), reinterpret_cast<uLongf*>(&compressedDataSize), reinterpret_cast<const Bytef*>(&data[0]), dataSize);
            compressedData.resize(compressedDataSize);

            if(zlibRet != Z_OK) {
                if(zlibRet == Z_MEM_ERROR) std::cerr << "zlib compress memory error\n";
                else if(zlibRet == Z_BUF_ERROR) std::cerr << "zlib compress buffer error\n";
                else std::cerr << "zlib compress error\n";

                return 1;
            }
        }
    }

    fmt::print("text: {}\ncode: {}\n", dataSize, compressedDataSize);

    return 0;
}

int Legf::Entry::Decompress() {
    fmt::print("text: {}\ncode: {}\n", dataSize, compressedDataSize);

    if(!dataSize || !compressedDataSize || !compressedData.size()) return 1;
    if(compType == COMP_NONE) return 0;
    else {
        if(compType == COMP_LZSS) {
            data.resize(dataSize);

            dataSize = unlzss(reinterpret_cast<u8*>(&compressedData[0]), compressedDataSize, reinterpret_cast<u8*>(&data[0]), dataSize);
            data.resize(dataSize);
        } else if(compType == COMP_ZLIB) {
            data.resize(dataSize);
            int zlibRet = uncompress(reinterpret_cast<Bytef*>(&data[0]), reinterpret_cast<uLongf*>(&dataSize), reinterpret_cast<Bytef*>(&compressedData[0]), compressedDataSize);
            if(zlibRet != Z_OK) {
                if(zlibRet == Z_MEM_ERROR) std::cerr << "zlib decompress memory error\n";
                else if(zlibRet == Z_BUF_ERROR) std::cerr << "zlib decompress buffer error\n";
                else if(zlibRet == Z_DATA_ERROR) std::cerr << "zlib decompress data error\n";
                else std::cerr << "zlib decompress error\n";
                
                return 1;
            }
        }
    }

    return 0;
}

int Legf::Read(const std::string& filename) {
    entries.clear();

    std::ifstream inf(filename);
    if(!inf.is_open()) return 1;

    std::string magic;
    inf.read(magic.data(), 4);

    // if(magic != "LEGF") return 1;

    int entryCount;
    inf.read(reinterpret_cast<char*>(&entryCount), 4);
    entries.resize(entryCount);

    for(int i = 0; i < entryCount; i++) {
        char j;
        while(inf.get(j) && j) {
            entries[i].filename += j;
        }

        inf.read(reinterpret_cast<char*>(&entries[i].resType), 4);
        inf.read(reinterpret_cast<char*>(&entries[i].isCompressed), 4);
        if(entries[i].isCompressed) {
            inf.read(reinterpret_cast<char*>(&entries[i].compType), 4);
            inf.read(reinterpret_cast<char*>(&entries[i].compressedDataSize), 4);
            inf.read(reinterpret_cast<char*>(&entries[i].dataSize), 4);
            entries[i].compressedData.resize(entries[i].compressedDataSize);
            inf.read(reinterpret_cast<char*>(&entries[i].compressedData[0]), entries[i].compressedDataSize);

            if(entries[i].Decompress()) {
                std::cerr << __func__ << " decompress error\n";
            }
        } else {
            inf.read(reinterpret_cast<char*>(&entries[i].dataSize), 4);
            entries[i].data.resize(entries[i].dataSize);
            inf.read(reinterpret_cast<char*>(&entries[i].data[0]), entries[i].dataSize);
        }
    }

    inf.close();

    return 0;
}

int Legf::Write(const std::string& filename) {
    std::ofstream outf(filename);
    if(!outf.is_open()) return 1;

    outf.write("LEGF", 4);
    int entryCount = entries.size();
    outf.write(reinterpret_cast<char*>(&entryCount), 4);

    for(int i = 0; i < entryCount; i++) {
        outf.write(entries[i].filename.c_str(), entries[i].filename.size() + 1);
        outf.write(reinterpret_cast<char*>(&entries[i].resType), 4);
        outf.write(reinterpret_cast<char*>(&entries[i].isCompressed), 4);
        if(entries[i].isCompressed) {
            outf.write(reinterpret_cast<char*>(&entries[i].compType), 4);
            outf.write(reinterpret_cast<char*>(&entries[i].compressedDataSize), 4);
            outf.write(reinterpret_cast<char*>(&entries[i].dataSize), 4);
            outf.write(reinterpret_cast<char*>(&entries[i].compressedData[0]), entries[i].compressedDataSize);
        } else {
            outf.write(reinterpret_cast<char*>(&entries[i].dataSize), 4);
            outf.write(reinterpret_cast<char*>(&entries[i].data[0]), entries[i].dataSize);
        }
    }

    outf.close();

    return 0;
}
