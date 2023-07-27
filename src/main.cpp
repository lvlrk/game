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

int main() {
    Legf legf;

    //Legf::Entry entry;
    //entry.FromFile("cloud99.wav", Legf::RES_AUDIO);

    //legf.entries.push_back(entry);

    //legf.Write("res.lgf");

    if(legf.Read("res.lgf")) std::cerr << "uh oh\n";

    return 0;
}
#endif
