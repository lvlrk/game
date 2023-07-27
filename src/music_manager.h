#pragma once

#include <string>
#include <memory>
#include <map>
#include "music_wrapper.h"

class MusicManager {
public:
    MusicWrapper *cMusic;
    std::map<std::string, std::unique_ptr<MusicWrapper>> music;
};
