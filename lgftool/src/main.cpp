#include <iostream>
#include <string>
#include "legf.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cerr << "Usage: lgftool [archive] [z,l/*] [FILE]..." << std::endl;

        return 1;
    }

    std::string filename = argv[1];
    char compress = *argv[2];

    Legf res;

    for(int i = 3; i < argc; i++) {
        Legf::Entry entry;

        entry.FromFile(argv[i]);
        if(compress == 'z') entry.Compress(Legf::COMP_ZLIB);
        if(compress == 'l') entry.Compress(Legf::COMP_LZSS);

        res.entries.push_back(entry);
    }

    if(res.Write(filename)) {
        std::cerr << "lgftool: write error\n";

        return 1;
    }

    if(res.Read(filename)) {
        std::cerr << "lgftool: read error?\n";

        return 1;
    }

    return 0;
}
