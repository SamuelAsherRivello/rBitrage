#include "client/rBitrage/systems/AssetLoaderSystem.h"

namespace RMC::rBitrage 
{
    /**
     * System for loading any assets
     */
    AssetLoaderSystem::AssetLoaderSystem(Game& game) : System(game) 
    {

    }

    void AssetLoaderSystem::OnInitialize() 
    {
    }
    
    void AssetLoaderSystem::LoadAllAssets()
    {
        //TODO: instead of loading things during 'add' methods. Wait, and do it all here instead
    }
} 
