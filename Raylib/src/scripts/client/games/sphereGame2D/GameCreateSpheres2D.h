#include "CameraSystem.h"
#include "Cube2D.h"
#include "DebugSystem.h"
#include "ApplicationSystem.h"
#include "Game.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "AssetLoaderSystem.h" 
#include "Sphere2D.h"
#include "Model3D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


int gameCreateSpheres2D()
{
    Game game = Game();
 
    //Overrides
    game.cameraSystemMode = CameraSystemMode::Cam2D; //camera mode
    game.world.GetSize() = game.screen.GetSize();   //balls bounds off world bounds
    game.isDebug = true; //show gizmos

    //
    game.Initialize();

    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/itch.io/projectTemplate/Ball01.png");
    loaderSystem->AddAsset<Image>("Background01", "src/assets/images/itch.io/projectTemplate/Background01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
    loaderSystem->LoadAllAssets();

    // FrameRenderLayer::PreCamera
    Sprite2D background = Sprite2D(game, "Background01", FrameRenderLayer::PreCamera);
    background.ResizeAssetTo({game.screen.GetSize().x, game.screen.GetSize().y, 0});
    background.SetPosition({game.screen.GetSize().x/2, game.screen.GetSize().y/2, 0});
    game.AddActor(&background);
 

    for (int i = 0; i < 10; i++)
    {
        Ball2D sphere = Ball2D(game, "Ball01");
        sphere.SetPosition(game.world.GetCenter());

        float x = (std::rand() % 11 - 5) * 100;
        float y = (std::rand() % 11 - 5) * 100;
        sphere.SetVelocity({x, y, 0});
        game.AddActor(&sphere);
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