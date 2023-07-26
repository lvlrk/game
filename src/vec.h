#pragma once

class Vec2 {
public:
    Vec2(int x, int y);
    void operator+(const Vec2& vec);
    void operator-(const Vec2& vec);

    int x;
    int y;
};
