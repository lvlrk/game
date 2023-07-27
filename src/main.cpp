#define P_GAME 0
#define P_TEST 1
#define PROG P_GAME

#if PROG == P_GAME
#include "app.h"

int main(int argc, char **argv) {
    App main(argc, argv);

    if(argc > 1) {
        main.info.Print();

        return 0;
    } else return main.Run();
}
#endif
#if PROG == P_TEST
#include <iostream>
#include "legf.h"

int main(int argc, char **argv) {
    int read = 1;

    if(!read) {
        Legf legf;

        Legf::Entry entry;

        for(int i = 1; i < argc; i++) {
            entry.FromFile(argv[i]);
            entry.Compress(Legf::COMP_ZLIB);

            legf.entries.push_back(entry);
        }

        if(legf.Write("res.lgf")) std::cerr << "Legf write error\n";
    } else {
        Legf legf;

        if(legf.Read("res.lgf")) std::cerr << "Legf read error\n";
    }

    return 0;
}
#endif
