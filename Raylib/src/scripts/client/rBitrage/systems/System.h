#pragma once
#include <raylib.h>
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/interfaces/ILifecycle.h"
#include <iostream>

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;
        
    class System  : public ILifecycle
    {
    public:

        System(Game& game);
        virtual ~System(); 

        //INTERFACE: ILifecycle
        virtual void OnInitialize() override; //setup "me"
        virtual void OnInitialized()  override; //setup 'dependencies"
        virtual void OnFixedUpdate(float fixedDeltaTime)  override;
        virtual void OnFrameUpdate(float deltaTime)  override;
        virtual void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;  

    protected:
        Game& _game;
    };
}

