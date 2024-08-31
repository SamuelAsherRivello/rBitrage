#pragma once
#include <vector>
#include "Actor.h"
#include "System.h"
#include <memory>
#include <chrono>

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
        void AddActor(Actor* actor);
        std::vector<Actor*>  GetActors();
        void RemoveActor(Actor* actor);

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
        Vector3 size;
        Color backgroundColor;
        bool isDebug = false;
        int targetFPS = 120;
        float fixedUpdateInterval = 0.2; 

    private:
        std::vector<System*> _systems;
        std::chrono::steady_clock _deltaClock;
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