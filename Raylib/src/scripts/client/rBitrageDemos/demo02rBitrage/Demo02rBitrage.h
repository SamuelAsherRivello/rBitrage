#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//


using namespace RMC::rBitrage;


int Demo02rBitrage() 
{
    // Create Game
    Game2D game = Game2D();


    // OPTIONAL: Set Overrides
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.title = "Demo 02 rBitrage";
    game.screen.SetSize({1920, 1080, 0});
    game.world.SetSize({555, 555, 0});
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
        Ball2D* actorPtr = new Ball2D(game, "Ball01"); 
        Ball2D actor = *actorPtr;
        actor.SetPosition(game.world.GetCenter());
        actor.SetIsDebug(true);
        game.AddActor(&actor); 

        actor.SetScale({2, 2, 2});
        actor.GetBounds().SetPivot({-0.5f, -0.5f, -0.5f});

        Vector3 velocity2 = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity2 = Vector3Multiply(velocity2, {100, 100, 100});
        actor.SetVelocity(velocity2);

        auto actorSharedPointer2 = std::make_shared<Ball2D>(actor);
        _actors.push_back(actorSharedPointer2);
        game.AddActor(actorSharedPointer2.get()); 

        //         // FrameRenderLayer::Camera2D
        // Ball2D actor = Ball2D(game, "Ball01"); 
        // actor.SetPosition(game.world.GetCenter());
        // actor.SetIsDebug(true);
        // game.AddActor(&actor); 
        // actor.GetBounds().SetSize({25, 25, 25});

        // Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        // velocity = Vector3Multiply(velocity, {100, 100, 100});
        // actor.SetVelocity(velocity);

        // auto actorSharedPointer = std::make_shared<Ball2D>(actor);
        // _actors.push_back(actorSharedPointer);
        // game.AddActor(actorSharedPointer.get()); 
    //}


    Ball2D& actor01 = static_cast<Ball2D&>(*_actors.at(0));

    Shape2D circleShape2D = Shape2D(game, new CircleShapeData2D());
    circleShape2D.SetScale({200, 200, 200});
    circleShape2D.SetPosition(Vector3Add(game.world.GetCenter(), Vector3{0, 0, 0}));
    //game.AddActor(&circleShape2D); 


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
    //game.AddActor(&hudUI);

    //game.GetSystem<SceneSystem>()->currentScene->AddActor(&hudUI);

  


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

            //std::cout << "b1: " << Utilities::ToString(actor01.GetBounds()) << std::endl;
        }

        

        if (game.GetSystem<InputSystem>()->IsActionPressed("debug"))
        {
            game.GetSystem<CameraSystem>()->camera2D.zoom = .1;
            game.GetSystem<CameraSystem>()->camera2D.offset = {0,0};
            game.GetSystem<CameraSystem>()->camera2D.target = GetMousePosition();
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