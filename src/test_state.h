#pragma once

#include <string>
#include "state.h"

class TestState: public State {
public:
    TestState(const std::string& text);
    void Update();
    void Draw();
private:
    std::string text;
};
