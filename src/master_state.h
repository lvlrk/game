#pragma once

#include "app.h"
#include "state.h"

class MasterState: public State {
public:
    MasterState(App& app);
    void Update();
private:
    App& app;
};
