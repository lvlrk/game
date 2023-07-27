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

    class Entry {
    public:
        void FromFile(const std::string& filename,
              int resType = RES_DATA);

        std::string filename;
        int resType;
        int dataSize;
        std::vector<char> data;
    };

    int Read(const std::string& filename);
    int Write(const std::string& filename);

    std::vector<Entry> entries;
};

// LEGF
// entryCount
// memTables[entryCount]
// entries[entryCount]
