#include <iostream>
#include <memory>
#include <algorithm>
#include "Game.h"
#include "System.h"
#include "CameraSystem.h" 
#include "DebugSystem.h" 
#include "InputSystem.h" 
#include "PhysicsSystem.h" 
#include "ActorSystem.h" 

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
    InitWindow(size.x, size.y, "Raylib Template Project");
    SetTargetFPS(targetFPS);

    //NOTE: Order matters 
    //      affecting all subsequent lifecycle
    AddSystem(new RMC::ProjectTemplate::CameraSystem(*this)); 
    AddSystem(new RMC::ProjectTemplate::InputSystem(*this)); 
    AddSystem(new RMC::ProjectTemplate::PhysicsSystem(*this)); 
    AddSystem(new RMC::ProjectTemplate::ActorSystem(*this)); 
    AddSystem(new RMC::ProjectTemplate::DebugSystem(*this)); 

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
    if (!HasSystem<RMC::ProjectTemplate::ActorSystem>())
    {
        std::cout << "AddActor() Failed" << std::endl;
    }
    GetSystem<RMC::ProjectTemplate::ActorSystem>()->AddActor(actor);
}

void Game::RemoveActor(Actor* actor) {
    if (!HasSystem<RMC::ProjectTemplate::ActorSystem>())
    {
        std::cout << "RemoveActor() Failed" << std::endl;
    }
    GetSystem<RMC::ProjectTemplate::ActorSystem>()->RemoveActor(actor);
}

std::vector<Actor*> Game::GetActors()
{
    if (!HasSystem<RMC::ProjectTemplate::ActorSystem>())
    {
        std::cout << "GetActors() Failed" << std::endl;
    }
    return GetSystem<RMC::ProjectTemplate::ActorSystem>()->GetActors();
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

    BeginMode2D(GetSystem<RMC::ProjectTemplate::CameraSystem>()->camera2D);

    for (System* system : _systems) {
        system->OnFrameRender(FrameRenderLayer::Camera);
    }

    EndMode2D();

    for (System* system : _systems) {
        system->OnFrameRender(FrameRenderLayer::PostCamera);
    }

    EndDrawing();

}