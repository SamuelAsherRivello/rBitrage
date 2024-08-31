#include "CameraSystem.h"
#include "Cube2D.h"
#include "DebugSystem.h"
#include "Game.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "Sphere2D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


// PERFORMANCE
//      TODO: Why does the ball flicker when moving (this started when I added the camera follow)
// CODING STANDARDS
//      TODO: Make a new "rBitrage.h" that contains every 'h' so users only need to include that ONE thing?
// NEW FEATURES
//      TODO: Draw items by SceneGraph first (more work), then position.z second (easier). Instead as currently, by  _actors[index]
//      TODO: Add hot reloading
//      TODO: Add pooling (of arbitrary type perhaps, but Actor is the key use case for bullets)
//      TODO: Actor DrawTexturePro supports pivot. Add it to actor and set to center by default? -- See https://docs.unity3d.com/ScriptReference/Sprite-pivot.html
// IMPROVEMENTS
//      TODO: Scope how much physics we want. Alot? Import 3rd party. A little, then add concept of CollisionGroups to existing IsCollididing() and be done.

int main()
{
    Game game = Game();

    //Calls System:OnInitialize
    game.Initialize();

    // FrameRenderLayer::PreCamera
    Actor2D background = Actor2D(game, "src/assets/images/itch.io/projectTemplate/Background01.png", FrameRenderLayer::PreCamera);
    background.SetSize({game.size.x, game.size.y, 0});
    background.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&background);

    // FrameRenderLayer::Camera
    Cube2D cube01 = Cube2D(game);
    cube01.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&cube01);

    Sphere2D sphere01 = Sphere2D(game);
    sphere01.SetPosition({game.size.x/4, game.size.y/4, 0});
    sphere01.SetVelocity({100, 200, 0});
    game.AddActor(&sphere01);

    Sphere2D sphere02 = Sphere2D(game);
    sphere02.SetPosition({game.size.x/3, game.size.y/3, 0});
    sphere02.SetVelocity({-200, 100, 0});
    game.AddActor(&sphere02);

    Actor2D boundary = Actor2D(game, "src/assets/images/itch.io/projectTemplate/Boundary01.png");
    boundary.SetSize({game.size.x, game.size.y, 0});
    boundary.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&boundary);

    // FrameRenderLayer::PostCamera
    Actor2D foreground = Actor2D(game, "src/assets/images/itch.io/projectTemplate/Foreground01.png", FrameRenderLayer::PostCamera);
    foreground.SetSize({game.size.x, game.size.y, 0});
    foreground.SetPosition({game.size.x/2, game.size.y/2, 0});
    game.AddActor(&foreground);

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);


    //
    if (game.HasSystem<CameraSystem>())
    {
        game.GetSystem<CameraSystem>()->SetTargetActor(&cube01);
    }

    //
    while (!WindowShouldClose())
    {
        //Calls System:OnFrameUpdate **AND** System:OnFixedUpdate
        game.UpdateFrame();

        //Calls System:OnFrameRender
        game.RenderFrame();
    
    }
    CloseWindow();
    return 0;
}