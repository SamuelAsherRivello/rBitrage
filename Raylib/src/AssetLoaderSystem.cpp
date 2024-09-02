#include "Game.h"
#include "AssetLoaderSystem.h"
#include <iostream>

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

} 
