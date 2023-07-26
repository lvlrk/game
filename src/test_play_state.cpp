#include <raylib.h>
#include "test_play_state.h"

TestPlayState::TestPlayState():
player("test") {}

void TestPlayState::Input() {
    if(IsKeyPressed('w')) player.position.y--;
    if(IsKeyPressed('s')) player.position.y++;
    if(IsKeyPressed('a')) player.position.x--;
    if(IsKeyPressed('d')) player.position.x++;
}

void TestPlayState::Update() {

}

void TestPlayState::Draw() {
    DrawRectangle(player.position.x, player.position.y, 20, 20, MAROON);
}
