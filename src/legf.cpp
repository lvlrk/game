#include <iostream>
#include <fstream>
#include "legf.h"

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
        entries[i].filename = "";

        char j;
        while(inf.get(j) && j) {
            entries[i].filename += j;
        }

        std::cout << entries[i].filename << std::endl;

        inf.read(reinterpret_cast<char*>(&entries[i].resType), 4);
        inf.read(reinterpret_cast<char*>(&entries[i].dataSize), 4);
        entries[i].data.resize(entries[i].dataSize);
        inf.read(reinterpret_cast<char*>(&entries[i].data[0]), entries[i].dataSize);
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
        outf.write(reinterpret_cast<char*>(&entries[i].dataSize), 4);
        outf.write(reinterpret_cast<char*>(&entries[i].data[0]), entries[i].dataSize);
    }

    outf.close();

    return 0;
}
