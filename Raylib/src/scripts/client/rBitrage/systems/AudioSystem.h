#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/systems/AssetLoaderSystem.h"



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
