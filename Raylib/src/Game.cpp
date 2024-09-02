#include "ActorSystem.h"
#include "ApplicationSystem.h"
#include "AudioSystem.h"
#include "CameraSystem.h"
#include "DebugSystem.h"
#include "Game.h"
#include "Screen.h"
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include "LoaderSystem.h"
#include "System.h"
#include <algorithm>
#include <iostream>
#include <memory>

namespace RMC::rBitrage 
{
    Game::Game() : screen(1920, 1080) {

        //KEEP These values hardcoded HERE. Override using public API as desired.
        backgroundColor = {53, 137, 202, 255};
        fixedUpdateInterval = .2; //0.2, Seconds between fixed updates
        title = "rBitrage Template";  //KEEP Here. Over-set publicaclly
        isDebug = false;  
        targetFPS = 120; //KEEP: 120, Frame updates per second
        world = World();

    }

    Game::~Game() {
        //TODO: I read that std::vector clean up their children.
        //      What else must I do here to clean the game?
    }


    void Game::Initialize() 
    {

        if (_isInitialized)
        {
            return;
        }

        InitWindow(screen.size.x, screen.size.y, title);
        SetTargetFPS(targetFPS);

        //NOTE: Order here matters...
        //      affecting order of subsequent lifecycle calls
        AddSystem(new ActorSystem(*this));
        AddSystem(new ApplicationSystem(*this));
        AddSystem(new AudioSystem(*this));
        AddSystem(new CameraSystem(*this));
        AddSystem(new InputSystem(*this));
        AddSystem(new LoaderSystem(*this));
        AddSystem(new PhysicsSystem(*this));

        if (this->isDebug) 
        {
            AddSystem(new DebugSystem(*this));
        }

        for (System* system : _systems) 
        {
            system->OnInitialize();
        }


        //TODO: Move to other place or keep it 'game specific' here?
        if (HasSystem<InputSystem>())
        {
            InputSystem* inputSystem = GetSystem<InputSystem>();

            //UP
            Action upAction;
            //IsDown
            upAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_W); });
            upAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_UP); });
            upAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP); });
            //IsDown
            upAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_W); });
            upAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_UP); });
            upAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP); });
            //
            inputSystem->AddAction("up", upAction);

            //Down
            Action downAction;
            //IsDown
            downAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_S); });
            downAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_DOWN); });
            downAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN); });
            //IsDown
            downAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_S); });
            downAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_DOWN); });
            downAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN); });
            //
            inputSystem->AddAction("down", downAction);

            //Left
            Action leftAction;
            //IsDown
            leftAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_A); });
            leftAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_LEFT); });
            leftAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT); });
            //IsDown
            leftAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_A); });
            leftAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_LEFT); });
            leftAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT); });
            //
            inputSystem->AddAction("left", leftAction);

            //Right
            Action rightAction;
            //IsDown
            rightAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_D); });
            rightAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_RIGHT); });
            rightAction.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT); });
            //IsDown
            rightAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_D); });
            rightAction.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_RIGHT); });
            rightAction.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT); });
            //
            inputSystem->AddAction("right", rightAction);

            //Action
            Action action;
            //IsDown
            action.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_ENTER); });
            action.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_SPACE); });
            action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_UP); });
            action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT); });
            action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN); });
            action.AddBinding(ActionType::IsPressed, []() { return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT); });
            //IsDown
            action.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_ENTER); });
            action.AddBinding(ActionType::IsDown, []() { return IsKeyDown(KEY_SPACE); });
            action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP); });
            action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT); });
            action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN); });
            action.AddBinding(ActionType::IsDown, []() { return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT); });
            //
            inputSystem->AddAction("action", action);

            //Fullscreen
            Action fullscreenAction;
            //IsDown
            fullscreenAction.AddBinding(ActionType::IsPressed, []() { return IsKeyPressed(KEY_F); });
            //
            inputSystem->AddAction("fullscreen", fullscreenAction);
        }

        Initialized();

    }

    void Game::Initialized() {

        if (_isInitialized)
        {
            return;
        }

        for (System* system : _systems) {
            system->OnInitialized();
        }
        
        _isInitialized = true;
    }


    void Game::AddSystem(System* system) {
        _systems.push_back(system);
    }


    void Game::RemoveSystem(System* system) {
        _systems.erase(std::remove(_systems.begin(), _systems.end(), system), _systems.end());
    }

    void Game::AddActor(Actor* actor) {
        if (!HasSystem<ActorSystem>())
        {
            std::cout << "AddActor() Failed" << std::endl;
        }
        GetSystem<ActorSystem>()->AddActor(actor);
    }

    void Game::RemoveActor(Actor* actor) {
        if (!HasSystem<ActorSystem>())
        {
            std::cout << "RemoveActor() Failed" << std::endl;
        }
        GetSystem<ActorSystem>()->RemoveActor(actor);
    }

    std::vector<Actor*> Game::GetActors()
    {
        if (!HasSystem<ActorSystem>())
        {
            std::cout << "GetActors() Failed" << std::endl;
        }
        return GetSystem<ActorSystem>()->GetActors();
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

        BeginMode2D(GetSystem<CameraSystem>()->camera2D);

        for (System* system : _systems) {
            system->OnFrameRender(FrameRenderLayer::Camera);
        }

        EndMode2D();

        for (System* system : _systems) {
            system->OnFrameRender(FrameRenderLayer::PostCamera);
        }

        EndDrawing();

    }
}