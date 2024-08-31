#include "Game.h"
#include "ApplicationSystem.h"
#include "InputSystem.h"

namespace RMC::rBitrage 
{
    /**
     * System for showing developer-facing info
     * in the console and onscreen. 
     */
    ApplicationSystem::ApplicationSystem(Game& game) : System(game) 
    {

    }

    void ApplicationSystem::OnInitialize() 
    {

    }

    void ApplicationSystem::OnInitialized() 
    {

    }


    void ApplicationSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        // std::cout << "OnFixedUpdate(" << fixedDeltaTime << ")" << std::endl;
    }


    void ApplicationSystem::OnFrameUpdate(float deltaTime) 
    {
        if (_game.HasSystem<InputSystem>())
        {
            if (_game.GetSystem<InputSystem>()->IsActionPressed("fullscreen"))
            {
                if (IsWindowFullscreen())
                {
                    // if we are full screen, then go back to the windowed size
                    SetWindowSize(_game.size.x, _game.size.y);
                }
                else
                {
                    // if we are not full screen, set the window size to match the monitor we are on
                    int display = GetCurrentMonitor();
                    SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
                }

                
                //NOTE: By default this changes the MONITOR resolution to match the GAME
                ToggleFullscreen();
            }
        }
    }


    void ApplicationSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
        
    }

    bool ApplicationSystem::RaylibWindowShouldClose() 
    {
        return WindowShouldClose();
    }
    void ApplicationSystem::RaylibCloseWindow() 
    {
        return CloseWindow();
    }
} 
