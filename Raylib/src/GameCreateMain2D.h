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
// POOLING
//      TODO: Think about a factory for actors. ActorPool.Create(ActorType) or ??


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
    loaderSystem->LoadAllAssets();
 
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