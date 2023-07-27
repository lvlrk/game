#pragma once

#include <string>
#include <raylib.h>
#include "legf.h"

class MusicWrapper {
public:
    MusicWrapper(const std::string& filename, Legf& res);
    ~MusicWrapper();
    void Update();
    
    bool ok = true;
    bool play = false;
    float timePlayed = 0.0f;
    bool paused = false;
private:
    const std::string filename;
    Music music;
    Legf& res;
};
