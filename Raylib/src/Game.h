#pragma once
#include <vector>
#include "Actor.h"
#include "System.h"
#include <memory>
#include <chrono>
#include "World.h"
#include "CameraSystemMode.h"
#include "Screen.h"

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of System class
    class System;
    class Actor;

    class Game
    {
    public:

        //Constructor
        Game();
        ~Game();

        //Actor
        std::vector<std::unique_ptr<Actor>> GetActors();
        void AddActor(std::unique_ptr<Actor> actor);
        void RemoveActor(std::unique_ptr<Actor> actor);

        //Lifecycle
        void Initialize();
        void Initialized();
        void AddSystem(System *system);
        void RemoveSystem(System* system);
        template <typename T>
        bool HasSystem() const;
        template <typename T>
        T* GetSystem() const;


        //Lifecycle
        void UpdateFrame();
        void RenderFrame(); 

        //
        bool GetIsInitialized() const { return _isInitialized; }

        //Fields
        Color backgroundColor;
        bool isDebug;
        int targetFPS;
        CameraSystemMode cameraSystemMode;
        float fixedUpdateInterval;
        const char * title;
        World world;
        Screen screen;

    private:
        std::vector<System*> _systems;
        float _lastFixedUpdate = 0;
        bool _isInitialized = false;

    };



    //TODO: Why can't I put this in the cpp file?
    template <typename T>
    bool Game::HasSystem() const {
        for (System* system : _systems) {
            if (typeid(*system) == typeid(T)) {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    T* Game::GetSystem() const {
        for (System* system : _systems) {
            if (typeid(*system) == typeid(T)) {
                return dynamic_cast<T*>(system);
            }
        }
        return nullptr;
    }
}