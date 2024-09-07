#include <raylib.h>
#include "client/rBitrage/rBitrage.h"
#include "client/rBitrageDemos/demo01Raylib/Ball.h"
using namespace RMC;


int Demo01Raylib() 
{

    // Initialization
    const char *screenTitle = "Demo 01 Raylib";
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int fontSize = 50;
\

    // Create Window
    InitWindow(screenWidth, screenHeight, screenTitle);
    SetTargetFPS(120);


    // Create Ball
    const char* assetPath = "./src/assets/images/Ball01.png";
    Vector2 position = { screenWidth / 2, screenHeight / 2 };
    Vector2 velocity = { 700, 500 };
    float radius = 3;
    Ball ball(assetPath, position, velocity, radius);


    // Demonstrate logging to VS Code terminal window
    std::cout << "\n********************" << std::endl;
    std::cout << "   Hello World!       " << std::endl;
    std::cout << "********************\n" << std::endl;


    // Game Loop - Click escape to close window
    while (!WindowShouldClose()) 
    {

        // Input - Click spacebar to reset ball position
        if (IsKeyPressed(KEY_SPACE))
        {
            ball.SetPosition (position);
        }


        // Update
        ball.FrameUpdate(GetFrameTime());


        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);


        // UI
        int textWidth = MeasureText(screenTitle, fontSize);
        int textHeight = 50;
        DrawText
            (
                screenTitle, 
                screenWidth / 2 - textWidth/2, 
                screenHeight / 2 - textHeight/2, 
                fontSize, 
                GRAY
            );


        // Ball
        ball.FrameRender();
        EndDrawing();
    }


    // Cleanup
    CloseWindow();
    return 0;

}