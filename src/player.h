#pragma once

#include <string>
#include <glm/vec2.hpp>

class Player {
public:
    Player(const std::string& name);
    void Update();
    void Draw();
private:
    const std::string name;
    glm::vec2 position;
    float moveSpeed = 200.0f;
};
