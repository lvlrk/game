#include "vec.h"

Vec2::Vec2(int x, int y):
    x{x},
y{y} {}

void Vec2::operator+(const Vec2& vec) {
    x += vec.x;
    y += vec.y;
}

void Vec2::operator-(const Vec2& vec) {
    x -= vec.x;
    y -= vec.y;
}
