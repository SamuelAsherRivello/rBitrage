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
    game.screen.SetSize({1920, 1080, 0});
    game.world.SetSize({1920, 1080, 0});
    game.screen.SetPivotAtCenter();
    game.world.SetPivotAtCenter();
    game.isDebug = true;                  //true, show ANY gizmos
    game.screen.isDebug = true;           //true, show THIS gizmo
    game.world.isDebug = true;            //true, show THIS gizmo


    // Initialize
    game.Initialize();


      // Demonstrate logging to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/Ball01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();

   std::vector<std::shared_ptr<Actor>> _actors;
    //for (int i = 0; i < 2; ++i)
    //{
        // FrameRenderLayer::Camera2D
        Ball2D actor = Ball2D(game, "Ball01"); 
        actor.SetPosition(game.world.GetCenter());
        actor.SetIsDebug(true);
        game.AddActor(&actor); 

        Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity = Vector3Multiply(velocity, {100, 100, 100});
        actor.SetVelocity(velocity);

        auto actorSharedPointer = std::make_shared<Ball2D>(actor);
        _actors.push_back(actorSharedPointer);
        game.AddActor(actorSharedPointer.get()); 
    //}
    Ball2D& actor01 = static_cast<Ball2D&>(*_actors.at(0));


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

  


    // Game Loop - Click escape to close window
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {
        // Input - Click spacebar to reset ball position
        if (game.GetSystem<InputSystem>()->IsActionPressed("action"))
        {
            actor01.SetPosition(game.world.GetCenter());
        

            Vector3 velocity = Random::GetRandomVector3({-3, -3, 0}, {3, 3, 0});
            velocity = Vector3Multiply(velocity, {200, 200, 0});
            actor01.SetVelocity(velocity);
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