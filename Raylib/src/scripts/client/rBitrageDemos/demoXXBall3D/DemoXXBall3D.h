#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//
using namespace RMC::rBitrage;




int DemoXXBall3D() 
{
    // Create Game
    Game3D game = Game3D();


    // OPTIONAL: Set Overrides
    game.title = "Demo XX Ball3D";
    game.isDebug = true;
    //game.world.isDebug = true;
    //game.screen.isDebug = true;
    const int ACTORS_COUNT_MAX = 100;

    // Initialize
    game.Initialize();


    // Log a message to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball", "src/assets/images/Ball01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->LoadAllAssets();


    // Actors
    std::vector<std::shared_ptr<Actor>> actors;
    for (float i = 0; i < ACTORS_COUNT_MAX; ++i)
    {

        // FrameRenderLayer::Camera2D
        auto actor = std::make_shared<Ball3D>(game);
        actors.push_back(actor);
        game.AddActor(actor.get());
        
        // CLASS Properties
        float scale = Random::GetRandomFloat(20, 50);
        actor->SetScale({scale, scale, scale});
        actor->SetPosition(game.world.GetCenter());
        actor->SetIsDebug(true);

        // SUBCLASS Properties
        Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity = Vector3Multiply(velocity, {200, 200, 200});
        actor->SetVelocity(velocity);

    }


    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game, 40);
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
            Ball3D* actor01 = static_cast<Ball3D*>(actors.at(0).get());
            
            // CLASS Properties
            float scale = Random::GetRandomFloat(0.5, 1.5);
            actor01->SetScale({scale, scale, scale});
            actor01->SetPosition(game.world.GetCenter());

            // SUBCLASS Properties
            Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
            velocity = Vector3Multiply(velocity, {200, 200, 200});
            actor01->SetVelocity(velocity);

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