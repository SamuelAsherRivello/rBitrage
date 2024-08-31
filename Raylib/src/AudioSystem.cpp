#include "Game.h"
#include "AudioSystem.h"

namespace RMC::rBitrage 
{
    /**
     * System for playing audio
     */
    AudioSystem::AudioSystem(Game& game) : System(game) 
    {

    }


    AudioSystem::~AudioSystem()
    {
        for (auto &sound : _soundsByName) {
            UnloadSound(sound.second);
        }
    }
   

    void AudioSystem::OnInitialize() 
    {
        InitAudioDevice();
        AddSound ("src/assets/audio/sfx/Hit01.wav", "Hit01");
        AddSound ("src/assets/audio/sfx/Hit03.wav", "Hit03");
    }

    void AudioSystem::AddSound(const char *fileName, const char *soundName) 
    {
        Sound sound = LoadSound(fileName);
        if (HasSound(soundName)) {  // 
            _soundsByName[std::string(soundName)] = sound;  // replace
        } else {
            _soundsByName[std::string(soundName)] = sound;  // add new
        }
    }

    bool AudioSystem::HasSound(const char *soundName) 
    {
        return _soundsByName.find(soundName) != _soundsByName.end();
    }

    Sound AudioSystem::GetSound(const char *soundName) 
    {
        return _soundsByName[soundName];
    }

    //TODO: Change name to "PlaySound" when I figure out how to do global::PlaySound()
    void AudioSystem::PlaySound2(const char *soundName)
    {
        if (HasSound(soundName)) {
            PlaySound(GetSound(soundName));
        }
    }
} 
