#include "CameraSystem.h"
#include "Cube2D.h"
#include "DebugSystem.h"
#include "ApplicationSystem.h"
#include "CameraSystemMode.h"
#include "Game.h"
#include "HudUI2D.h"
#include "InputSystem.h"
#include "AssetLoaderSystem.h" 
#include "Sphere2D.h"
#include <iostream>
#include <raylib.h>
using namespace RMC::rBitrage;


// PERFORMANCE
//      TODO: Why does the ball flicker when moving (this started when I added the camera follow)
// CODING STANDARDS
//      TODO: Make a new "rBitrage.h" that contains every 'h' so users only need to include that ONE thing?
//      TODO: Do a full pass over all methods per pointers. Pointers as arguments? Pointers as return values? Efficient + Standardized?
// NEW FEATURES
//      TODO: Draw items by SceneGraph first (more work), then position.z second (easier). Instead as currently, by  _actors[index]
//      TODO: Add hot reloading
//      TODO: Add pooling (of arbitrary type perhaps, but Actor is the key use case for bullets)
//      TODO: Actor DrawTexturePro supports pivot. Add it to actor and set to center by default? -- See https://docs.unity3d.com/ScriptReference/Sprite-pivot.html
// IMPROVEMENTS
//      TODO: Scope how much physics we want. Alot? Import 3rd party. A little, then add concept of CollisionGroups to existing IsCollididing() and be done.
//      TODO: Change System:OnInitialize to System:OnInitializeAsync and have game wait for it
int gameCreateMain2D()
{
    Game game = Game();

    //Overrides
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.world.size = game.screen.size;   //balls bounds off world bounds
    game.isDebug = true; //show gizmos

    //Calls System:OnInitialize **AND** System:OnInitialized
    game.Initialize();


    if (!game.GetIsInitialized())
    {
        return 0;
    }


    if (!game.HasSystem<AssetLoaderSystem>())
    {
        return 0;
    }

    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Ball01", "src/assets/images/itch.io/projectTemplate/Ball01.png");
    loaderSystem->AddAsset<Image>("Background01", "src/assets/images/itch.io/projectTemplate/Background01.png");
    loaderSystem->AddAsset<Image>("Boundary01", "src/assets/images/itch.io/projectTemplate/Boundary01.png");
    loaderSystem->AddAsset<Image>("Foreground01", "src/assets/images/itch.io/projectTemplate/Foreground01.png");
    loaderSystem->AddAsset<Image>("Paddle01", "src/assets/images/itch.io/projectTemplate/Paddle01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
 
    // FrameRenderLayer::PreCamera
    Actor2D background = Actor2D(game, "Background01", FrameRenderLayer::PreCamera);
    background.SetSize({game.screen.size.x, game.screen.size.y, 0});
    background.SetPosition(game.world.center);
    game.AddActor(&background);

    // FrameRenderLayer::Camera
    Cube2D cube01 = Cube2D(game);
    cube01.SetOpacity(1.0f);
    cube01.SetPosition({game.screen.size.x/2, game.screen.size.y/2, 0});
    game.AddActor(&cube01);

    Cube2D cube02 = Cube2D(game);
    cube02.SetOpacity(0.5f);
    cube02.SetPivot({0,0,0}); // upper left
    cube02.SetPosition({game.screen.size.x/2 + 300, game.screen.size.y/2, 0});
    game.AddActor(&cube02);

    Cube2D cube03 = Cube2D(game);
    cube03.SetOpacity(.25f);
    cube03.SetPivot({1, 1, 1}); // lower right
    cube03.SetPosition({game.screen.size.x/2 + 600, game.screen.size.y/2, 0});
    game.AddActor(&cube03);






    Sphere2D sphere01 = Sphere2D(game);
    sphere01.SetPosition({game.screen.size.x/4, game.screen.size.y/4, 0});
    sphere01.SetVelocity({100, 200, 0});
    game.AddActor(&sphere01);

    Sphere2D sphere02 = Sphere2D(game);
    sphere02.SetPosition({game.screen.size.x/3, game.screen.size.y/3, 0});
    sphere02.SetVelocity({-200, 100, 0});
    game.AddActor(&sphere02);

    Actor2D boundary = Actor2D(game, "Boundary01");
    boundary.SetSize({game.world.size});
    boundary.SetPosition(game.world.center);
    game.AddActor(&boundary);

    // FrameRenderLayer::PostCamera
    Actor2D foreground = Actor2D(game, "Foreground01", FrameRenderLayer::PostCamera);
    foreground.SetSize({game.screen.size.x, game.screen.size.y, 0});
    foreground.SetPosition({game.screen.size.x/2, game.screen.size.y/2, 0});
    game.AddActor(&foreground);

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);


    //
    if (game.HasSystem<CameraSystem>())
    {
        //game.GetSystem<CameraSystem>()->SetTargetActor(&cube01);
    }

    //
    if (game.HasSystem<ApplicationSystem>())
    {
        while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
        {
            //Calls System:OnFrameUpdate **AND** System:OnFixedUpdate
            game.UpdateFrame();

            //Calls System:OnFrameRender
            game.RenderFrame();
        
        }
        game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();
    }

    return 0;
}