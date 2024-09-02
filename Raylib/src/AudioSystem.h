#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"
#include <unordered_map>
#include <string>
#include "AssetLoaderSystem.h"

namespace RMC::rBitrage 
{
    class AudioSystem : public System 
    {
        public:
            AudioSystem(Game& game);
            ~AudioSystem();
            void OnInitialize() override;
            void OnInitialized() override;

            //
            void PlaySound(const char *soundName);

        private:
            AssetLoaderSystem* _assetLoaderSystem;
            
    };

} 
