
#pragma once
//
#include "client/rBitrage/Game2D.h"
#include "client/rBitrage/systems/AssetLoaderSystem.h"
#include "client/rBitrage/systems/ApplicationSystem.h"
#include "client/rBitrage/systems/TweenSystem.h"
#include "client/rBitrage/actors/Sprite2D.h"
//
#include "3rdParty/tweeny/tweeny/tweeny.h"
//
#include "client/rBitrageDemos/actors/HudUI2D.h"
#include "client/rBitrageDemos/demoXXOrbitGame2D/OrbitPlayer.h"
//
using namespace RMC::rBitrage;


bool OnStep2(int x, int y) 
{
    std::cout << "x: " << x << " y" << y << std::endl;
    if (x == y) return true;
    return false;
}

bool OnStep1(int x) 
{
    std::cout << "x: " << x <<std::endl;
    return false;
}

int DemoXXOrbitGame2D()
{


    Game2D game = Game2D();

    //Optional: Override any defaults
    game.screen.size = { 720, 1080};
    game.screen.center = {720/2, 1080/2};
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.isDebug = true; //show gizmos

    //Calls System:OnInitialize **AND** System:OnInitialized
    game.Initialize();

    //The endinge works off assetKeys which must be first loaded from paths
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Bullet", "src/assets/images/Ball01.png");
    loaderSystem->AddAsset<Image>("Enemy", "src/assets/images/EnemyFace01.png");
    loaderSystem->AddAsset<Image>("Background", "src/assets/images/OrbitBackground01.png");
    loaderSystem->AddAsset<Image>("OrbitPlayer", "src/assets/images/Paddle01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
    loaderSystem->LoadAllAssets();
 
    // FrameRenderLayer::PreCamera
    Sprite2D background = Sprite2D(game, "Background", FrameRenderLayer::PreCamera);
    background.SetSize({game.screen.size.x, game.screen.size.y, 0});
    background.SetPosition(game.screen.center);
    game.AddActor(&background);

    // FrameRenderLayer::Camera2D
    Sprite2D enemy = Sprite2D(game, "Enemy", FrameRenderLayer::Camera2D);
    enemy.SetSize({game.screen.size.x/3, game.screen.size.y/3, 0});
    enemy.SetPosition(game.screen.center);
    game.AddActor(&enemy);

    OrbitPlayer orbitPlayer = OrbitPlayer(game);
    orbitPlayer.SetSize({game.screen.size.x/7, game.screen.size.y/20, 0});
    orbitPlayer.SetOrbitCenter(game.screen.center);
    orbitPlayer.SetIsDebug(true); //show gizmos
    game.AddActor(&orbitPlayer);

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);

    int x = enemy.GetSize().x;
    int y = enemy.GetSize().y;
    int z = enemy.GetSize().z;

    auto tween = game.GetSystem<TweenSystem>()->from(0, 0, 0).to(x, y, z).during(100).via(tweeny::easing::exponentialOut).onStep([&](float x, float y, float z)
    {
        enemy.SetSize(Vector3{x, y, z});
        return false;
    });
        
    // lambdas
    while (!game.GetSystem<ApplicationSystem>()->RaylibWindowShouldClose())
    {

        //Calls System:OnFrameUpdate **AND** System:OnFixedUpdate
        game.UpdateFrame();

        //Calls System:OnFrameRender
        game.RenderFrame();
    
    }
    game.GetSystem<ApplicationSystem>()->RaylibCloseWindow();

    return 0;
}