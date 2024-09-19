#include <raylib.h>
//
#include "client/rBitrage/rBitrage.h"
//
using namespace RMC::rBitrage;

int DemoXXShape2D() 
{
    // Create Game
    Game2D game = Game2D();


    // OPTIONAL: Set Overrides
    game.title = "Demo XX Shape2D";
    game.isDebug = true;                  //true, show ANY gizmos
    game.screen.isDebug = true;           //true, show THIS gizmo
    game.world.isDebug = true;            //true, show THIS gizmo


    // Initialize
    game.Initialize();


    // Log a message to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Assets
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->LoadAllAssets();


    // Actors
    CircleShapeData2D* shapeData2D = new CircleShapeData2D(RED, 50);
    Shape2D circleShape2D = Shape2D(game, shapeData2D);
    circleShape2D.SetIsDebug(true);
    circleShape2D.SetPosition(Vector3Add(game.world.GetCenter(), Vector3{0, 0, 0}));
    game.AddActor(&circleShape2D); 



    // FrameRenderLayer::PostCamera
    // OPTIONAL: Add HUD UI
    HudUI2D hudUI = HudUI2D(game);
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