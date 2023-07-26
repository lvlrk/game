#include <raylib.h>
#include "player.h"

Player::Player(const std::string& name):
    name{name},
position(0.0f, 0.0f) {}

void Player::Update() {
    if(position.y - moveSpeed * GetFrameTime() > 0 && IsKeyDown(KEY_W)) position.y -= moveSpeed * GetFrameTime();
    if(position.y + moveSpeed * GetFrameTime() < GetScreenHeight() - 20 && IsKeyDown(KEY_S)) position.y += moveSpeed * GetFrameTime();
    if(position.x - moveSpeed * GetFrameTime() > 0 && IsKeyDown(KEY_A)) position.x -= moveSpeed * GetFrameTime();
    if(position.x + moveSpeed * GetFrameTime() < GetScreenWidth() - 20 && IsKeyDown(KEY_D)) position.x += moveSpeed * GetFrameTime();
}

void Player::Draw() {
    DrawRectangle(position.x, position.y, 20, 20, MAROON);
}
