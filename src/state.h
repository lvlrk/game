#pragma once

class State {
public:
    State();
    virtual ~State();
    virtual void Input();
    virtual void Update();
    virtual void Draw();
};
