#include "Game.h"
#include "DebugSystem.h"

namespace RMC::rBitrage 
{
    /**
     * System for showing developer-facing info
     * in the console and onscreen. 
     */
    DebugSystem::DebugSystem(Game& game) : System(game) 
    {

    }

    void DebugSystem::OnInitialize() 
    {

    }


    void DebugSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        // std::cout << "OnFixedUpdate(" << fixedDeltaTime << ")" << std::endl;
    }


    void DebugSystem::OnFrameUpdate(float deltaTime) 
    {
        // std::cout << "OnFrameUpdate(" << deltaTime << ")" << std::endl;
    }


    void DebugSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
        
        //FPS
        if (frameRenderLayer != FrameRenderLayer::PostCamera )
        {
            return;
        }

        DrawFPS(50, 120);   

        //Draw world first, thicker
        DrawWorldSizeHalf();
        DrawWorldBounds();

        //Draw screen after, thinner
        DrawScreenSizeHalf();
        DrawScreenBounds();
     

        //Draw box around actors for debugging
        // for (Actor* actor : _game.GetActors()) {
        //     if (actor->GetFrameRenderLayer() != frameRenderLayer)
        //     {
        //         continue;
        //     }
        //     DrawRectangleLinesEx(actor->GetBounds(), 4, RED);
        // }
    }

    void DebugSystem::DrawWorldSizeHalf() 
    {
        //HORIZONTAL
        DrawLineEx({0, _game.world.size.y/2}, {_game.world.size.x, _game.world.size.y/2}, _worldStroke, _worldColor);

        //VERTICAL
        DrawLineEx({_game.world.size.x/2, 0}, {_game.world.size.x/2, _game.world.size.y}, _worldStroke, _worldColor);

    }

    void DebugSystem::DrawScreenSizeHalf() 
    {
        //HORIZONTAL
        DrawLineEx({0, _game.screen.size.y/2}, {_game.screen.size.x, _game.screen.size.y/2}, _screenStroke, _screenColor);

        //VERTICAL
        DrawLineEx({_game.screen.size.x/2, 0}, {_game.screen.size.x/2, _game.screen.size.y}, _screenStroke, _screenColor);

    }

    void DebugSystem::DrawScreenBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.screen.size.x, _game.screen.size.y}, _screenStroke, _screenColor);
    }

    void DebugSystem::DrawWorldBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.world.size.x, _game.world.size.y}, _worldStroke, _worldColor);
    }
} 
