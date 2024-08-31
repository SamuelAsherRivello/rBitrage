#include "Game.h"
#include "LoaderSystem.h"
#include <iostream>

namespace RMC::rBitrage 
{
    /**
     * System for loading any assets
     */
    LoaderSystem::LoaderSystem(Game& game) : System(game) 
    {

    }

    void LoaderSystem::OnInitialize() 
    {
    }

} 
