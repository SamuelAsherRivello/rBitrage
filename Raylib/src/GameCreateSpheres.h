#include "CameraSystem.h"
#include "Cube2D.h"
#include "DebugSystem.h"
#include "ApplicationSystem.h"
#include "Game.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "AssetLoaderSystem.h" 
#include "Sphere2D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


int gameCreateSpheres()
{
    Game game = Game();

    //Overrides
    game.world.size = game.screen.size;   //balls bounds off world bounds
    game.isDebug = true; //show gizmos

    //
    game.Initialize();

    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/itch.io/projectTemplate/Ball01.png");
    loaderSystem->AddAsset<Image>("Background01", "src/assets/images/itch.io/projectTemplate/Background01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
 
    for (int i = 0; i < 10; i++)
    {
        Sphere2D* sphere = new Sphere2D(game);
        sphere->SetPosition(game.world.center);

        float x = (std::rand() % 11 - 5) * 100;
        float y = (std::rand() % 11 - 5) * 100;
        sphere->SetVelocity({x, y, 0});
        game.AddActor(sphere);
    }

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);


    //
    if (game.HasSystem<ApplicationSystem>())
    {
        while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
        {

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                std::cout << "Left Mouse Button Pressed\n";
            }

            game.UpdateFrame();
            game.RenderFrame();
        
        }
        game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    }

    return 0;
}