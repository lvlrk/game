#include <raylib.h>
#include "master_state.h"

MasterState::MasterState(App& app):
app{app} {}

void MasterState::Input() {
    if(IsKeyPressed('1')) {
        app.stateMan.cState = std::move(app.stateMan.states["test"]).get();
    }

    if(IsKeyPressed('2')) {
        app.stateMan.cState = std::move(app.stateMan.states["test2"]).get();
    }
}

void MasterState::Update() {

}
