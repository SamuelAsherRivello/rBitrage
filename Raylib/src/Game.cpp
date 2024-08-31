#include "ActorSystem.h"
#include "AudioSystem.h"
#include "CameraSystem.h"
#include "DebugSystem.h"
#include "Game.h"
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include "System.h"
#include <algorithm>
#include <iostream>
#include <memory>

Game::Game() {
    size = {1600, 1000, 0};
    backgroundColor = {53, 137, 202, 255};
    isDebug = true;
    targetFPS = 120; //120, Frame updates per second
    fixedUpdateInterval = .2; //0.2, Seconds between fixed updates
}

Game::~Game() {
    //TODO: I read that std::vector clean up their children.
    //      What else must I do here to clean the game?
}


void Game::Initialize() {
    InitWindow(size.x, size.y, "rBitrage Template Project");
    SetTargetFPS(targetFPS);

    //NOTE: Order here matters...
    //      affecting order of subsequent lifecycle calls
    AddSystem(new RMC::rBitrage::ActorSystem(*this));
    AddSystem(new RMC::rBitrage::AudioSystem(*this));
    AddSystem(new RMC::rBitrage::CameraSystem(*this));
    AddSystem(new RMC::rBitrage::DebugSystem(*this));
    AddSystem(new RMC::rBitrage::InputSystem(*this));
    AddSystem(new RMC::rBitrage::PhysicsSystem(*this));

    for (System* system : _systems) {
        system->OnInitialize();
    }

}

void Game::AddSystem(System* system) {
    _systems.push_back(system);
}


void Game::RemoveSystem(System* system) {
    _systems.erase(std::remove(_systems.begin(), _systems.end(), system), _systems.end());
}

void Game::AddActor(Actor* actor) {
    if (!HasSystem<RMC::rBitrage::ActorSystem>())
    {
        std::cout << "AddActor() Failed" << std::endl;
    }
    GetSystem<RMC::rBitrage::ActorSystem>()->AddActor(actor);
}

void Game::RemoveActor(Actor* actor) {
    if (!HasSystem<RMC::rBitrage::ActorSystem>())
    {
        std::cout << "RemoveActor() Failed" << std::endl;
    }
    GetSystem<RMC::rBitrage::ActorSystem>()->RemoveActor(actor);
}

std::vector<Actor*> Game::GetActors()
{
    if (!HasSystem<RMC::rBitrage::ActorSystem>())
    {
        std::cout << "GetActors() Failed" << std::endl;
    }
    return GetSystem<RMC::rBitrage::ActorSystem>()->GetActors();
}


void Game::UpdateFrame() {
    float deltaTime = GetFrameTime();  // GetFrameTime() returns time in seconds
    double elapsedEver = GetTime();    // GetTime() returns time in seconds

    ////////////////////////////////
    // FRAME UPDATE
    ////////////////////////////////

    // Update at variable rate
    for (System* system : _systems) {
        system->OnFrameUpdate(deltaTime);
    }


    ////////////////////////////////
    // FIXED UPDATE
    ////////////////////////////////

    // Track accumulated error
    static double accumulatedError = 0.0;

    // Calculate the elapsed time since the last fixed update (convert to milliseconds)
    double elapsedTimeSinceLastFixedUpdate = (elapsedEver) - _lastFixedUpdate;

    // Add the error to the elapsed time to compensate
    elapsedTimeSinceLastFixedUpdate += accumulatedError;

    // Update at fixed rate if enough time has passed
    if (elapsedTimeSinceLastFixedUpdate >= fixedUpdateInterval) {
        double updateDelta = elapsedTimeSinceLastFixedUpdate; // Use the real delta

        for (System* system : _systems) {
            system->OnFixedUpdate(updateDelta);
        }

        // Calculate the error for this frame
        accumulatedError = elapsedTimeSinceLastFixedUpdate - fixedUpdateInterval;

        // Update the last fixed update time to the current time
        _lastFixedUpdate += fixedUpdateInterval;
    }
}



void Game::RenderFrame() {

    BeginDrawing();
    ClearBackground(backgroundColor);

    for (System* system : _systems) {
        system->OnFrameRender(FrameRenderLayer::PreCamera);
    }

    // Camera camera = { 0 };
    // camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    // camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    // camera.fovy = 45.0f;
    // camera.projection = CAMERA_PERSPECTIVE;

    // BeginMode3D(camera);

    //     // Draw enemy-box
    //     DrawCube({0,0,0}, 3, 3, 3, BLUE);
    //     DrawGrid(10, 1.0f);

    // EndMode3D();

    BeginMode2D(GetSystem<RMC::rBitrage::CameraSystem>()->camera2D);

    for (System* system : _systems) {
        system->OnFrameRender(FrameRenderLayer::Camera);
    }

    EndMode2D();

    for (System* system : _systems) {
        system->OnFrameRender(FrameRenderLayer::PostCamera);
    }

    EndDrawing();

}