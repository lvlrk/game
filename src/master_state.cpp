#include <raylib.h>
#include "master_state.h"

MasterState::MasterState(App& app):
app{app} {}

void MasterState::Input() {
    if(app.stateMan.cState == app.stateMan.states["test"].get() ||
    app.stateMan.cState == app.stateMan.states["test2"].get()) {
        if(IsKeyPressed('1')) {
            app.stateMan.cState = app.stateMan.states["test"].get();
        }

        if(IsKeyPressed('2')) {
            app.stateMan.cState = app.stateMan.states["test2"].get();
        }
    }
}

void MasterState::Update() {

}
