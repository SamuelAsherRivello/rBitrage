#include "CameraSystem.h"
#include "Cube2D.h"
#include "DebugSystem.h"
#include "ApplicationSystem.h"
#include "Game.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "LoaderSystem.h" 
#include "Sphere2D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


int gameCreateSpheres()
{
    Game game = Game();

    game.Initialize();
    LoaderSystem* loaderSystem = game.GetSystem<LoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/itch.io/projectTemplate/Ball01.png");
 
    // FrameRenderLayer::PreCamera
    Actor2D background = Actor2D(game, "Background01", FrameRenderLayer::PreCamera);
    background.SetSize({game.size.x, game.size.y, 0});
    background.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&background);

    for (int i = 0; i < 10; i++)
    {
        Sphere2D* sphere = new Sphere2D(game);
        sphere->SetPosition({game.size.x/2, game.size.y/2, 0});

        float x = std::rand() % -100 + std::rand() % 2000;
        float y = std::rand() % -100 + std::rand() % 200;
        sphere->SetVelocity({x, y, 0});
        game.AddActor(sphere);
    }

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);


    //
    if (game.HasSystem<CameraSystem>())
    {
        //game.GetSystem<CameraSystem>()->GetCamera2D().offset = {game.size.x/2, game.size.y/2};
    }

    //
    if (game.HasSystem<ApplicationSystem>())
    {
        while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
        {
            game.UpdateFrame();
            game.RenderFrame();
        
        }
        game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    }

    return 0;
}