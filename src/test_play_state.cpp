#include <raylib.h>
#include "test_play_state.h"

TestPlayState::TestPlayState():
player("test") {}

void TestPlayState::Update() {
    player.Update();
}

void TestPlayState::Draw() {
    player.Draw();

    // DrawText(TextFormat("Now Playing: %s", ))
}
