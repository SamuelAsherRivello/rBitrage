#include <raylib.h>
#include <algorithm>
#include <memory>
//
#include "client/rBitrage/Game3D.h"
#include "client/rBitrage/utilities/Random.h"
#include "client/rBitrage/systems/CameraSystem.h"
//
#include "client/rBitrageDemos/actors/Ball3D.h"

using namespace RMC::rBitrage;


int DemoXXStressTest3D() 
{
    // Create Game
    Game3D game = Game3D();
    game.world.center = {0, 0, 0};
    game.world.size = {20, 20, 20};
    game.cameraSystemMode = CameraSystemMode::Cam3D;
    game.title = "Demo XX Stress Test 3D";
    game.isDebug = true; //Show FPS
    game.world.isDebug = true; //Show grid

    // Initialize
    game.Initialize();


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/Ball01.png");
    //very noisy... loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();


    std::vector<std::shared_ptr<Actor>> _actors;
    for (int i = 0; i < 1000; ++i)
    {
        // FrameRenderLayer::Camera2D
        Ball3D ball3D = Ball3D(game); 
        ball3D.SetPosition(game.world.center);
        
        Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity = Vector3Multiply(velocity, {1, 1, 1});
        ball3D.SetVelocity(velocity);

        auto x = std::make_shared<Ball3D>(ball3D);
        _actors.push_back(x);
        game.AddActor(x.get()); 
    }

    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game);
    hudUI.SetTextLowerRight(game.title);
    game.AddActor(&hudUI);


    // Demonstrate logging to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Game Loop - Click escape to close window
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {

        // Input - Click spacebar to reset ball position
        if (game.GetSystem<InputSystem>()->IsActionPressed("action"))
        {
        }


        // Move
        game.UpdateFrame();


        // Draw
        game.RenderFrame();
    

    }

    // Cleanup
    game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    return 0;


}