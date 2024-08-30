#pragma once
#include "rBitrage.h"
#include "client/rBitrage/types/CameraSystemMode.h"
#include "client/rBitrage/types/World.h"
#include "client/rBitrage/types/Screen.h"
#include <vector> //needed
#include <typeinfo> //needed

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
        std::vector<Actor*>  GetActors();
        void AddActor(Actor *actor);
        void RemoveActor(Actor *actor);

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