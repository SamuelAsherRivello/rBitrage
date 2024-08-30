#include <raylib.h>
#include "client/rBitrage/Game.h"
#include "client/rBitrageDemos/actors/Ball2D.h"
#include "client/rBitrage/actors/Shape2D.h"
#include "client/rBitrage/utilities/Random.h"
#include "client/rBitrage/systems/CameraSystem.h"
#include <algorithm>
#include <memory>

using namespace RMC::rBitrage;


int DemoXXStressTest2D() 
{
    // Create Game
    Game game = Game();
    game.title = "Demo XX Stress Test 2D";
    game.isDebug = true; //Show FPS

    // Initialize
    game.Initialize();


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/Ball01.png");
    //very noisy... loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();


    std::vector<std::shared_ptr<Actor>> _actors;




        // FrameRenderLayer::Camera2D
        Ball2D ball2D2 = Ball2D(game, "Ball01"); 
        ball2D2.SetPosition(game.world.center);
        
        Vector3 velocity2 = Random::GetRandomVector3({-3, -3, 0}, {3, 3, 0});
        velocity2 = Vector3Multiply(velocity2, {200, 200, 0});
        ball2D2.SetVelocity(velocity2);

        auto x1 = std::make_shared<Ball2D>(ball2D2);
        game.AddActor(x1.get()); 
     _actors.push_back(x1);


          // FrameRenderLayer::Camera2D
        Ball2D ball2D = Ball2D(game, "Ball01"); 
        ball2D.SetPosition(game.world.center);
        
        Vector3 velocity = Random::GetRandomVector3({-3, -3, 0}, {3, 3, 0});
        velocity = Vector3Multiply(velocity, {200, 200, 0});
        ball2D.SetVelocity(velocity);





      auto x2 = std::make_shared<Ball2D>(ball2D);
        game.AddActor(x2.get()); 
        _actors.push_back(x2);





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