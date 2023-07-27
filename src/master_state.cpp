#include <raylib.h>
#include "master_state.h"

MasterState::MasterState(App& app):
app{app} {}

void MasterState::Update() {
    if(app.stateMan.cState == app.stateMan.states["test"].get() ||
    app.stateMan.cState == app.stateMan.states["test2"].get()) {
        if(IsKeyPressed(KEY_ONE)) {
            app.stateMan.cState = app.stateMan.states["test"].get();
        }

        if(IsKeyPressed(KEY_TWO)) {
            app.stateMan.cState = app.stateMan.states["test2"].get();
        }
    }

    if(app.musicMan.cMusic->ok) {
        if(IsKeyPressed(KEY_SPACE)) {
            app.musicMan.cMusic->play = !app.musicMan.cMusic->play;
        }
    }
}
