#pragma once

#include <string>
#include "vec.h"

class Player {
public:
    Player(const std::string& name);

    friend class TestPlayState;
private:
    const std::string name;
    Vec2 position;
};
