#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//
#include "client/rBitrageDemos/actors/Ball2D.h"
#include "client/rBitrageDemos/actors/HudUI2D.h"

using namespace RMC::rBitrage;


int Demo02rBitrage() 
{
    // Create Game
    Game2D game = Game2D();


    // OPTIONAL: Set Overrides
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.title = "Demo 02 rBitrage";
    game.screen.size = game.world.size = {1920, 1080, 0};
    game.screen.center = game.world.center = {1920/2, 1080/2, 0};
    game.isDebug = true;                  //true, show ANY gizmos
    game.screen.isDebug = true;           //true, show THIS gizmo
    game.world.isDebug = true;            //true, show THIS gizmo


    // Initialize
    game.Initialize();


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/Ball01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();

    std::cout << "Assets Loaded\n" << std::endl;


     std::vector<Actor*> _actors;

    // FrameRenderLayer::Camera2D
    Ball2D sphere2D = Ball2D(game, "Ball01"); 
    sphere2D.SetPosition(game.world.center);
    sphere2D.SetSize({100, 100, 100});
    Vector3 velocity = Random::GetRandomVector3({-3, -3, 0}, {3, 3, 0});
    velocity = Vector3Multiply(velocity, {200, 200, 0});
    sphere2D.SetVelocity(velocity);
    game.AddActor(&sphere2D); 





    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game);
    const char* scoreText = "Score: 100";
    const char* livesText = "Lives: 003";
    const char* instructions = "Press [Space] to reset";
    const char* extra = game.title;
    hudUI.SetTextUpperLeft(scoreText);
    hudUI.SetTextUpperRight(livesText);
    hudUI.SetTextLowerLeft(instructions);
    hudUI.SetTextLowerRight(extra);
    game.AddActor(&hudUI);

    game.GetSystem<SceneSystem>()->currentScene->AddActor(&hudUI);

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
            sphere2D.SetPosition(game.world.center);

            Vector3 velocity = Random::GetRandomVector3({-3, -3, 0}, {3, 3, 0});
            velocity = Vector3Multiply(velocity, {200, 200, 0});
            sphere2D.SetVelocity(velocity);
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