#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//
using namespace RMC::rBitrage;

struct ActorData
{
    float radius;
    float angle;
    float velocityAngular = 30.0f;
    float velocityOrbital = 0.001f;
};

Vector3 GetNextPosition(Vector3 center, ActorData& actorData, float time, float frameTime)
{
    actorData.angle += actorData.velocityOrbital * time;
    return 
    {
        center.x + actorData.radius * std::cos(actorData.angle),
        center.y + actorData.radius * std::sin(actorData.angle),
        0
    };
}

int DemoXXSpinArt() 
{
    // Create Game
    Game2D game = Game2D();
    game.backgroundColor = BLACK;
    game.screen.SetSize({1400, 1400});
    game.world.SetSize(game.screen.GetSize());


    // OPTIONAL: Set Overrides
    game.title = "Demo XX Spin Art";
    const int ACTORS_COUNT_MAX = 100;


    // Initialize
    game.Initialize();


    // Log a message to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Spiral01", "src/assets/images/Spiral01.png");
    loaderSystem->AddAsset<Image>("Spiral02", "src/assets/images/Spiral02.png");
    loaderSystem->LoadAllAssets();


    // Actors
    std::vector<std::shared_ptr<Actor>> actors;
    std::vector<std::shared_ptr<ActorData>> actorDatas;
    const float angleIncrement = 0.05f; // adjust this value to control the spiral density
    for (float i = 0; i < ACTORS_COUNT_MAX; ++i)
    {
        // FrameRenderLayer::Camera2D
        auto actor = std::make_shared<Sprite2D>(game, "Spiral02");
        auto actorData = std::make_shared<ActorData>();
        actorDatas.push_back(actorData);
        actors.push_back(actor);
        game.AddActor(actor.get());

        // Spiral calculation
        float distance = i * angleIncrement; // increase the distance based on index
        actorData.get()->radius = distance * 100; // adjust this value to control the spiral's curvature
        actorData.get()->angle = (i / ACTORS_COUNT_MAX) * 360; // rotate around the center

        // CLASS Properties
        float scale = 0.3 + distance * 0.02f;
        actor->SetScale({scale, scale, scale});
     
        Vector3 position = GetNextPosition(game.screen.GetCenter(), *actorData.get(), GetTime(), GetFrameTime());
        actor->SetPosition(position);
    }


    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game, 40);
    const char* scoreText = "";
    const char* livesText = "";
    const char* instructions = "";
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
            // Loop through all actors
            for (auto& actor : actors)  
            {
                // Optional cast check
                if (dynamic_cast<Sprite2D*>(actor.get()))  
                {
                    auto sprite = dynamic_cast<Sprite2D*>(actor.get());
                    sprite->SetPosition(game.world.GetCenter());
                }
            }


        }

        // Loop through all actors
        for (int i = 0; i < actors.size(); i++)  
        {
            auto actor = actors[i];
            ActorData& actorData = *actorDatas[i];
            float time = GetTime();
            float frameTime = GetFrameTime();
            actor->SetRotation({0, 0, time * actorData.velocityAngular});
            
            Vector3 position = GetNextPosition(game.screen.GetCenter(), actorData, time, frameTime);
            actor->SetPosition(position);
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