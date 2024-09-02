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

        DrawWorldOrigin();
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

    void DebugSystem::DrawWorldOrigin() 
    {
        //HORIZONTAL
        DrawLineEx({0, _game.size.y/2}, {_game.size.x, _game.size.y/2}, 4, _worldColor);

        //VERTICAL
        DrawLineEx({_game.size.x/2, 0}, {_game.size.x/2, _game.size.y}, 4, _worldColor);

    }

    void DebugSystem::DrawScreenBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.size.x, _game.size.y}, 4, _screenColor);
    }
} 
