#pragma once

#include <vector>
#include "state_manager.h"
#include "music_manager.h"
#include "legf.h"

class App {
public:
    class ProgInfo {
    public:
        ProgInfo(const std::string& name,
                 int versionMax, int versionMid,
                 int versionMin);
        void Print();

        std::string name;
        int versionMax;
        int versionMid;
        int versionMin;
    };

    App(int argc, char **argv);
    int Run();

    ProgInfo info;

    int argc;
    char **argv;
    std::vector<std::string> args;

    bool shouldRun = true;

    friend class MasterState; // let MasterState access *all* members
private:
    StateManager stateMan;
    MusicManager musicMan; // MUSIC MAN!?!
    Legf res; // internal resource file
};
