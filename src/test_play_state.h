#pragma once

#include "state.h"
#include "player.h"

class TestPlayState: public State {
public:
    TestPlayState();
    void Update();
    void Draw();
private:
    Player player;
};
