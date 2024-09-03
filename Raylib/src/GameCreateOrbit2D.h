
//rBitrage
#include "rBitrage.h"
using namespace RMC::rBitrage;

//Orbit
#include "OrbitPlayer.h"

int gameCreateOrbit2D()
{
    Game game = Game();

    //Optional: Override any defaults
    game.screen.size = { 720, 1080};
    game.screen.center = {720/2, 1080/2};
    game.cameraSystemMode = CameraSystemMode::Cam2D;
    game.isDebug = true; //show gizmos

    //Calls System:OnInitialize **AND** System:OnInitialized
    game.Initialize();

    //The endinge works off assetKeys which must be first loaded from paths
    AssetLoaderSystem* loaderSystem = game.GetSystem<AssetLoaderSystem>();
    loaderSystem->AddAsset<Image>("Bullet", "src/assets/images/itch.io/projectTemplate/Ball01.png");
    loaderSystem->AddAsset<Image>("Enemy", "src/assets/images/itch.io/projectTemplate/EnemyFace01.png");
    loaderSystem->AddAsset<Image>("Background", "src/assets/images/itch.io/projectTemplate/OrbitBackground01.png");
    loaderSystem->AddAsset<Image>("OrbitPlayer", "src/assets/images/itch.io/projectTemplate/Paddle01.png");
    loaderSystem->AddAsset<Sound>("Hit01", "src/assets/audio/sfx/Hit01.wav");
    loaderSystem->AddAsset<Sound>("Hit03", "src/assets/audio/sfx/Hit03.wav");
    loaderSystem->LoadAllAssets();
 
    // FrameRenderLayer::PreCamera
    Actor2D background = Actor2D(game, "Background", FrameRenderLayer::PreCamera);
    background.SetSize({game.screen.size.x, game.screen.size.y, 0});
    background.SetPosition(game.screen.center);
    game.AddActor(&background);

    // FrameRenderLayer::Camera2D
    Actor2D enemy = Actor2D(game, "Enemy", FrameRenderLayer::Camera2D);
    enemy.SetSize({game.screen.size.x/3, game.screen.size.y/3, 0});
    enemy.SetPosition(game.screen.center);
    game.AddActor(&enemy);

    OrbitPlayer orbitPlayer = OrbitPlayer(game);
    orbitPlayer.SetSize({game.screen.size.x/7, game.screen.size.y/20, 0});
    orbitPlayer.SetOrbitCenter(game.screen.center);
    game.AddActor(&orbitPlayer);

    // FrameRenderLayer::PostCamera
    HudUI2D hudUI = HudUI2D(game);
    game.AddActor(&hudUI);


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