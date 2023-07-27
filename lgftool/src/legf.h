#pragma once

// L. vlrk's (Lvlrk)
// E. pic    (Eats)
// G. ame    (Guacamole)
// F. ormat  (Farts)

#include <vector>
#include <string>

class Legf {
public:
    enum ResType {
        RES_DATA = 0,
        RES_IMAGE = 1,
        RES_MODEL = 2,
        RES_AUDIO = 3
    };

    enum CompType {
        COMP_NONE = 0,
        COMP_LZSS = 1,
        COMP_ZLIB = 2
    };

    class Entry {
    public:
        void FromFile(const std::string& filename,
              int resType = RES_DATA);
        int Compress(int compType = COMP_NONE);
        int Decompress();

        std::string filename = "";
        int resType = RES_DATA;
        int isCompressed = false;
        int compType = COMP_NONE;
        int dataSize = 0;
        int compressedDataSize = 0;
        std::vector<char> data;
        std::vector<char> compressedData;
    };

    int Read(const std::string& filename);
    int Write(const std::string& filename);

    std::vector<Entry> entries;
};

// LEGF
// entryCount
// memTables[entryCount]
// entries[entryCount]
