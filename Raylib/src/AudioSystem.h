#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"
#include <unordered_map>
#include <string>

namespace RMC::rBitrage 
{
    class AudioSystem : public System 
    {
        public:
            AudioSystem(Game& game);
            ~AudioSystem();
            void OnInitialize() override;

            //
            bool HasSound(const char *soundName);
            Sound GetSound(const char *soundName);
            void AddSound(const char *fileName, const char *soundName);
            void PlaySound2(const char *soundName);

        private:
            std::unordered_map<std::string, Sound> _soundsByName;  
            
    };

} 
