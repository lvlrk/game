#include <iostream>
#include <raylib.h>
#include <fmt/core.h>
#include "app.h"
#include "test_state.h"
#include "master_state.h"
#include "test_play_state.h"

App::ProgInfo::ProgInfo(const std::string& name,
                       int versionMax, int versionMid,
                       int versionMin):
    name{name},
    versionMax{versionMax},
    versionMid{versionMid},
versionMin{versionMin} {}

void App::ProgInfo::Print() {
    std::cout << fmt::format("{:s}-{:d}.{:d}.{:d}\n",
                             name, versionMax,
                             versionMid, versionMin);
}

App::App(int argc, char **argv):
    argc{argc},
    argv{argv},
info("game", 0, 1, 1) {
    for(int i = 1; i < argc; i++) {
        args.resize(i);
        args[i - 1] = argv[i];
    }

    stateMan.states["master"] = std::unique_ptr<MasterState>(new MasterState(*this));
    stateMan.states["test"] = std::unique_ptr<State>(new TestState("dick"));
    stateMan.states["test2"] = std::unique_ptr<State>(new TestState("ass"));
    stateMan.states["testPlay"] = std::unique_ptr<State>(new TestPlayState);

    stateMan.cState = stateMan.states["testPlay"].get();
}

int App::Run() {
    InitWindow(800, 600, "Game");

    while(!WindowShouldClose() && shouldRun) {
        ClearBackground(BLACK);

        stateMan.states["master"].get()->Update();
        stateMan.cState->Update();

        BeginDrawing();
            stateMan.cState->Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
