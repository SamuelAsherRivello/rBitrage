#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//


using namespace RMC::rBitrage;


int DemoXXStressTest2D() 
{
    // Create Game
    Game2D game = Game2D();


    // OPTIONAL: Set Overrides
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.title = "Demo XX Stress Test";


    // Initialize
    game.Initialize();


    // Log a message to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball", "src/assets/images/Ball02.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();


    // Actors
    std::vector<std::shared_ptr<Actor>> actors;
    for (float i = 1; i < 22; ++i)
    {
        // FrameRenderLayer::Camera2D
        auto actor = std::make_shared<Ball2D>(game, "Ball");
        actors.push_back(actor);
        game.AddActor(actor.get());
        
        // CLASS Properties
        actor->SetPosition(game.world.GetCenter());
        actor->SetScale({0.5, 0.5, 0.5});
        actor->SetIsDebug(true);

        // SUBCLASS Properties
        Vector3 velocity2 = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity2 = Vector3Multiply(velocity2, {200, 200, 200});
        actor->SetVelocity(velocity2);
    }


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


    // Game Loop - Click escape to close window
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {
        // Input - Click spacebar to reset ball position
        if (game.GetSystem<InputSystem>()->IsActionPressed("action"))
        {
            Ball2D* actor01 = static_cast<Ball2D*>(actors.at(0).get());
            
            // CLASS Properties
            actor01->SetPosition(game.world.GetCenter());

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