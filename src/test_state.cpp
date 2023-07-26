#include <raylib.h>
#include "test_state.h"

TestState::TestState(const std::string& text):
text{text} {}

void TestState::Input() {

}

void TestState::Update() {

}

void TestState::Draw() {
    DrawText(text.c_str(), 0, 0, 20, MAROON);
}
