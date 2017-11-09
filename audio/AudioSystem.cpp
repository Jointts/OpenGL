//
// Created by Joonas on 11/7/2017.
//

#include <fmod_studio.hpp>
#include <cstdlib>
#include "AudioSystem.h"

FMOD_RESULT result;
FMOD::Studio::System* audioSystem = nullptr;

AudioSystem::AudioSystem() {
    CreateSystem();
}

void AudioSystem::CreateSystem(){
    result = FMOD::Studio::System::create(&audioSystem);
    if (result != FMOD_OK)
    {
//        std::printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}