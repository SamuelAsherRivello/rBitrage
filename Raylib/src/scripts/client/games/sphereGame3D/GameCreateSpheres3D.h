#include "CameraSystem.h"
#include "DebugSystem.h"
#include "ApplicationSystem.h"
#include "Game.h"
#include "Model3D.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "AssetLoaderSystem.h" 
#include "Sphere3D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


int gameCreateSpheres3D()
{
    Game game = Game();

    //Overrides
    game.cameraSystemMode = CameraSystemMode::Cam3D;
    game.world.size = game.screen.size;   //balls bounds off world bounds
    game.isDebug = true; //show gizmos

    //
    game.Initialize();

    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/itch.io/projectTemplate/Ball01.png");
    loaderSystem->AddAsset<Image>("Background01", "src/assets/images/itch.io/projectTemplate/Background01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
    loaderSystem->LoadAllAssets();

    for (int i = 0; i < 1; i++)
    {
        std::cout << "Sphere " << i << std::endl;
        Model3D sphere = Model3D(game, "");
        sphere.SetPosition(game.world.center);

        // float x = (std::rand() % 11 - 5) * 100;
        // float y = (std::rand() % 11 - 5) * 100;
        // sphere.SetVelocity({x, y, 0});
        game.AddActor(&sphere);
    }

    // FrameRenderLayer::PostCamera


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