#include <raylib.h>
#include <algorithm>
#include <memory>
#include <string>
#include <raymath.h>
//
#include "client/rBitrage/Game3D.h"
#include "client/rBitrage/utilities/Random.h"
#include "client/rBitrage/systems/CameraSystem.h"
//
#include "client/rBitrageDemos/actors/Duck3D.h"

using namespace RMC::rBitrage;


int DemoXXModel3D() 
{
    // Create Game
    Game3D game = Game3D();
    game.world.center = game.screen.center;
    game.world.size = {20, 20, 20};
    game.title = "Demo XX Model 3D";
    game.isDebug = true; //Show FPS
    game.world.isDebug = true; //Show grid

    // Initialize
    game.Initialize();

    // Demonstrate logging to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;

    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Texture2D>("DuckTexture2D01",  "src/assets/models/duck/textures/RubberDuck_AlbedoTransparency.png");
    loaderSystem->AddAsset<Model>    ("DuckModel01",      "src/assets/models/duck/model/RubberDuck_LOD0.obj");
    loaderSystem->LoadAllAssets();


    // FrameRenderLayer::Camera2D
    Duck3D model3D = Duck3D(game); 
    model3D.SetPosition(game.world.center);
    game.AddActor(&model3D); 


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
            model3D.SetRotation({0,0,0});
        }


        // Move
        game.UpdateFrame();
        int rotationY = Utilities::ToInt(model3D.GetRotation().y * RAD2DEG);
        std::string rotationYString = Utilities::ToString(rotationY);
        hudUI.SetTextUpperRight(("Rotation: " + rotationYString).c_str());

        // Draw
        game.RenderFrame();
    

    }

    // Cleanup
    game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    return 0;


}