#include <raylib.h>
#include <algorithm>
#include <memory>
#include <string>
#include <raymath.h>
//
#include "client/rBitrage/Game3D.h"
#include "client/rBitrage/utilities/Random.h"
#include "client/rBitrage/systems/CameraSystem.h"
#include "client/rBitrage/systems/ApplicationSystem.h"

#include "client/rBitrageDemos/actors/HudUI2D.h"
#include "client/rBitrageDemos/actors/Duck3D.h"

using namespace RMC::rBitrage;


int DemoXXModel3D() 
{
    // Create Game
    Game3D game = Game3D();
    game.title = "Demo XX Model 3D";
    game.isDebug = true; //Show FPS
    game.world.isDebug = true; //Show grid

    // Initialize
    game.Initialize();

    // Log a message to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;

    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Texture2D>("DuckTexture2D01",  "src/assets/models/duck/textures/RubberDuck_AlbedoTransparency.png");
    loaderSystem->AddAsset<Model>    ("DuckModel01",      "src/assets/models/duck/model/RubberDuck_LOD0.obj");
    loaderSystem->LoadAllAssets();


   std::vector<std::shared_ptr<Actor>> _actors;
    for (int i = 0; i < 100; ++i)
    {
        // FrameRenderLayer::Camera2D
        Duck3D actor = Duck3D(game); 
        actor.SetPosition(game.world.GetCenter());
        game.AddActor(&actor); 

        Vector3 velocity = Random::GetRandomVector3({-3, -3, -3}, {3, 3, 3});
        velocity = Vector3Multiply(velocity, {1, 1, 1});
        actor.SetVelocity(velocity);

        auto actorSharedPointer = std::make_shared<Duck3D>(actor);
        _actors.push_back(actorSharedPointer);
        game.AddActor(actorSharedPointer.get()); 
    }


  

    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game);
    hudUI.SetTextLowerLeft("Press [Space] to reset");
    hudUI.SetTextLowerRight(game.title);
    game.AddActor(&hudUI);


    // Game Loop - Click escape to close window
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {

        // Input - Click spacebar to reset rotation
        if (game.GetSystem<InputSystem>()->IsActionPressed("action"))
        {
            for (auto& actor : _actors)
            {
                actor->SetRotation({0, 0, 0});
                actor->SetPosition(game.world.GetCenter());
            }
        }


        // Move
        game.UpdateFrame();
        int rotationY = Utilities::ToInt(_actors.at(0)->GetRotation().y * RAD2DEG);
        std::string rotationYString = Utilities::ToString(rotationY);
        hudUI.SetTextUpperRight(("Rotation: " + rotationYString).c_str());

        // Draw
        game.RenderFrame(); 
    

    }

    // Cleanup
    game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    return 0;


}