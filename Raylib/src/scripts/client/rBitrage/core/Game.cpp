#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/systems/ActorSystem.h"
#include "client/rBitrage/systems/ApplicationSystem.h"
#include "client/rBitrage/systems/AssetLoaderSystem.h"
#include "client/rBitrage/systems/AudioSystem.h"
#include "client/rBitrage/systems/CameraSystem.h"
#include "client/rBitrage/systems/DebugSystem.h"
#include "client/rBitrage/systems/InputSystem.h"
#include "client/rBitrage/systems/TweenSystem.h"
#include "client/rBitrage/systems/SceneSystem.h"
#include "client/rBitrage/systems/PhysicsSystem.h"
#include "client/rBitrage/systems/System.h"
#include <algorithm>

namespace RMC::rBitrage 
{
    Game::Game() : 
    
        //DEFAULT: Decent for screen size
        screen(1920, 1080), 
        
        //DEFAULT: The world matches the screen, plus depth (at least for 2D this makes sense as default)
        world(1920, 1080, 1080) 

        {

        //KEEP These values hardcoded HERE. Override using public API as desired.
        backgroundColor = {53, 137, 202, 255};
        fixedUpdateInterval = .2; //0.2, Seconds between fixed updates
        title = "rBitrage Template";  //KEEP Here. Over-set publicaclly
        isDebug = false;  
        targetFPS = 120; //KEEP: 120, Frame updates per second
        cameraSystemMode = CameraSystemMode::Cam2DAnd3D;

    }

    Game::~Game() {
        //TODO: I read that std::vector clean up their children.
        //      What else must I do here to clean the game?
    }


    void Game::Initialize() 
    {

       if (GetIsInitialized())
        {
            return;
        }

        InitWindow(screen.size.x, screen.size.y, title);
        SetTargetFPS(targetFPS);

        //NOTE: Order here matters...
        //      affecting order of subsequent lifecycle calls
     
        AddSystem(new ApplicationSystem(*this));
        AddSystem(new AudioSystem(*this));
        AddSystem(new TweenSystem(*this));
        AddSystem(new CameraSystem(*this, CameraSystemMode::Cam2D));
        AddSystem(new InputSystem(*this));
        AddSystem(new AssetLoaderSystem(*this));
        AddSystem(new PhysicsSystem(*this));

        //TODO: Keep just one of these?
        AddSystem(new ActorSystem(*this));
        AddSystem(new SceneSystem(*this));

        if (this->isDebug) 
        {
            AddSystem(new DebugSystem(*this));
        }

        //Forward the game configuration to systems
        //so its easier for the dev-user to set it early
        //NOTE: this won't capture any future changes to game.cameraSystemMode by user. Ok? (No? change to setter)
        if (HasSystem<CameraSystem>())
        {
            GetSystem<CameraSystem>()->cameraSystemMode = this->cameraSystemMode;
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

       if (GetIsInitialized())
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
            std::cout << "RemoveActor() Failed, no system" << std::endl;
        }
        if (!GetSystem<ActorSystem>()->HasActor(actor))
        {
            std::cout << "RemoveActor() Failed, no actor" << std::endl;
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


    /**
     * Draws the frame.
     * we call all systems 3 times, before, during, and after camera
     * each system does 'nothing' except the on the 1? pass it wants. 
     */
    void Game::RenderFrame() {


        BeginDrawing();
        ClearBackground(backgroundColor);
        for (System* system : _systems) {
            system->OnFrameRender(FrameRenderLayer::PreCamera);
        }



        if (GetSystem<CameraSystem>()->cameraSystemMode != CameraSystemMode::Cam3D)
        {
            BeginMode2D(GetSystem<CameraSystem>()->camera2D);
            for (System* system : _systems) {
                system->OnFrameRender(FrameRenderLayer::Camera2D);
            }
            EndMode2D();
        }
       

        if (GetSystem<CameraSystem>()->cameraSystemMode != CameraSystemMode::Cam2D)
        {
            BeginMode3D(GetSystem<CameraSystem>()->camera3D);
            for (System* system : _systems) {
                system->OnFrameRender(FrameRenderLayer::Camera3D);
            }
            EndMode3D();
        }

        for (System* system : _systems) {
            system->OnFrameRender(FrameRenderLayer::PostCamera);
        }
        EndDrawing();

    }
}