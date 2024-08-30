#pragma once
#include <raylib.h>
#include "client/rBitrage/Game.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include <iostream>
namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;
        

    class System  
    {
    public:

        System(Game& game);
        virtual ~System(); 
        virtual void OnInitialize(); //setup "me"
        virtual void OnInitialized(); //setup 'dependencies"
        virtual void OnFixedUpdate(float fixedDeltaTime);
        virtual void OnFrameUpdate(float deltaTime);
        virtual void OnFrameRender(const FrameRenderLayer& frameRenderLayer);  

    protected:
        Game& _game;
    };
}

