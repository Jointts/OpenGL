//
// Created by Joonas on 11/7/2017.
//

#ifndef GAME_AUDIOMANAGER_H
#define GAME_AUDIOMANAGER_H
#include "AudioSystem.h"

class AudioManager {
public:
    static AudioManager *audioManager;

    static AudioSystem *audioSystem;

    AudioManager();

    static AudioManager *getInstance();
};


#endif //GAME_AUDIOMANAGER_H
