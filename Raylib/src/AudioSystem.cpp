#include "Game.h"
#include "AudioSystem.h"
#include "AssetLoaderSystem.h"

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
    }
   

    void AudioSystem::OnInitialize() 
    {
        InitAudioDevice();
    }

    void AudioSystem::OnInitialized() 
    {
        if (!_game.GetSystem<AssetLoaderSystem>())
        {
            std::cout << "ERROR: AudioSystem::OnInitialized() failed dependencies" << std::endl;
            return;
        }

        _assetLoaderSystem = _game.GetSystem<AssetLoaderSystem>();
    }
    

    void AudioSystem::PlaySound(const char *assetKey)
    {
        if (!_assetLoaderSystem->HasAsset<Sound>(assetKey))
        {
            std::cout << "ERROR: AudioSystem::PlaySound() failed asset" << std::endl;
            return;
        }

        //NOTE: "::" calls the raylib function. Its not recursion
        ::PlaySound(_assetLoaderSystem->GetAssetAsSound<Sound>(assetKey));
    }
} 
