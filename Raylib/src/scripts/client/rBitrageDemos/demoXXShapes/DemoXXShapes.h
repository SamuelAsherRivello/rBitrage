#include <raylib.h>
//
#include "client/rBitrage/Game2D.h"
#include "client/rBitrage/actors/Shape2D.h"
#include "client/rBitrage/systems/CameraSystem.h"
//
#include "client/rBitrageDemos/actors/Ball2D.h"
#include "client/rBitrageDemos/actors/Background2D.h"

using namespace RMC::rBitrage;


int DemoXXShapes() 
{
    // Create Game
    Game2D game = Game2D();
    game.title = "Demo XX Shapes";


    // Initialize
    game.Initialize();


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->LoadAllAssets();



    // FrameRenderLayer::Camera2D
    Background2D background2D = Background2D(game);
    game.AddActor(&background2D); 


    Shape2D rectangleShape2D = Shape2D(game, new RectangleShapeData2D());
    rectangleShape2D.GetTransform().Scale = {200, 200, 200};
    rectangleShape2D.SetPosition(Vector3Add(game.world.GetCenter(), Vector3{-200, 0, 0}));
    game.AddActor(&rectangleShape2D); 


    Shape2D circleShape2D = Shape2D(game, new CircleShapeData2D());
    circleShape2D.GetTransform().Scale = {200, 200, 200};
    circleShape2D.SetPosition(Vector3Add(game.world.GetCenter(), Vector3{200, 0, 0}));
    game.AddActor(&circleShape2D); 

    
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game);
    hudUI.SetTextUpperLeft("");
    hudUI.SetTextUpperRight("");
    hudUI.SetTextLowerLeft("");
    hudUI.SetTextLowerRight(game.title);
    game.AddActor(&hudUI);


    // Demonstrate logging to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;
    std::cout << Utilities::ToString(game.world.GetCenter()) << std::endl;
    
    // Game Loop - Click escape to close window
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {

        // Move
        game.UpdateFrame();


        // Draw
        game.RenderFrame();
    

    }

    // Cleanup
    game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    return 0;


}