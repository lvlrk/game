#include "music_wrapper.h"

MusicWrapper::MusicWrapper(const std::string& filename, Legf& res):
    filename{filename},
res{res} {
    for(const Legf::Entry& entry: res.entries) {
        if(entry.filename == filename) {
            music = LoadMusicStreamFromMemory(".wav", reinterpret_cast<const unsigned char*>(&entry.data[0]), entry.dataSize);

            ok = (music.stream.buffer != nullptr);

            if(ok) PlayMusicStream(music);
        }
    }
}

MusicWrapper::~MusicWrapper() {
    if(ok) UnloadMusicStream(music);
}

void MusicWrapper::Update() {
    if(ok) {
        if(play) {
            UpdateMusicStream(music);

            timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
            if (timePlayed > 1.0f) timePlayed = 1.0f;
        }
    }
}
