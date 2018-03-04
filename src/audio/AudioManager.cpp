//
// Created by Joonas on 11/7/2017.
//

#include "AudioManager.h"


AudioManager* AudioManager::audioManager = 0;
AudioSystem* AudioManager::audioSystem = 0;

AudioManager::AudioManager() {
    audioSystem = new AudioSystem();
}

AudioManager *AudioManager::getInstance() {
    if(!audioManager){
        audioManager = new AudioManager();
    }
    return audioManager;
}