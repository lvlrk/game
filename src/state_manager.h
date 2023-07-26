#pragma once

#include <string>
#include <memory>
#include <map>
#include "state.h"

class StateManager {
public:
    State *cState; // current state, automatically newest 'pushed' state via PushBack()
    std::map<std::string, std::unique_ptr<State>> states;
};
