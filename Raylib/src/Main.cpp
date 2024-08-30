#include <raylib.h>
#include "Sphere.h"
#include "Cube.h"
#include "Game.h"
#include <iostream>
#include "DebugSystem.h"
#include "InputSystem.h"
#include "CameraSystem.h"
using namespace RMC::ProjectTemplate;


//WIP: Thoughts on runtime behavior...
//TODO: Why does the ball flicker when moving (this started when I added the camera follow)

int main()
{
    Game game = Game();

    //Calls System:OnInitialize
    game.Initialize();

    // FrameRenderLayer::PreCamera
    Actor background = Actor(game, "src/assets/images/itch.io/projectTemplate/Background01.png", FrameRenderLayer::PreCamera);
    background.SetSize({game.size.x, game.size.y, 0});
    background.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&background);

    // FrameRenderLayer::Camera
    Cube cube01 = Cube(game);
    cube01.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&cube01);

    Sphere sphere01 = Sphere(game);
    sphere01.SetPosition({game.size.x/4, game.size.y/4, 0});
    game.AddActor(&sphere01);

    Sphere sphere02 = Sphere(game);
    sphere02.SetPosition({game.size.x/3, game.size.y/3, 0});
    game.AddActor(&sphere02);

    // FrameRenderLayer::PostCamera
    Actor foreground = Actor(game, "src/assets/images/itch.io/projectTemplate/Foreground02.png", FrameRenderLayer::PostCamera);
    foreground.SetSize({game.size.x, game.size.y, 0});
    foreground.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&foreground);

    //
    if (game.HasSystem<CameraSystem>())
    {
        game.GetSystem<CameraSystem>()->SetTargetActor(&cube01);
    }

    //
    while (!WindowShouldClose())
    {
        //Calls System:OnFrameUpdate **AND** System:OnFixedUpdate
        game.UpdateFrame();

        //Calls System:OnFrameRender
        game.RenderFrame();
    
    }
    CloseWindow();
    return 0;
}