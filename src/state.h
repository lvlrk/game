#pragma once

class State {
public:
    State();
    virtual ~State();
    virtual void Update();
    virtual void Draw();
};
