#include <raylib.h>
#include <iostream>
#include <memory>
#include "Game.h"
#include "ActorSystem.h"

namespace RMC::rBitrage 
{

    ActorSystem::ActorSystem(Game& game) : System(game) 
    {
        // Constructor to initialize the system.
    }

    /**
     * Lifecycle
     *
     * OnInitialize: Initializes the actor system.
     */
    void ActorSystem::OnInitialize() 
    {
        for (Actor* actor : _actors) {
            actor->OnInitialize();
        }
    }

    /**
     * OnFixedUpdate: Called every fixed time step.
     *
     * @param fixedDeltaTime The delta time since last fixed update.
     */
    void ActorSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        for (Actor* actor : _actors) {
            actor->OnFixedUpdate(fixedDeltaTime);
        }
    }

    /**
     * OnFrameUpdate: Called every frame.
     *
     * @param deltaTime The delta time since last update.
     */
    void ActorSystem::OnFrameUpdate(float deltaTime) 
    {
        for (Actor* actor : _actors) {
            actor->OnFrameUpdate(deltaTime);
        }
    }

    /**
     * OnFrameRender: Called every frame.
     */
    void ActorSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
        for (Actor* actor : _actors) {
            if (actor->GetFrameRenderLayer() == frameRenderLayer)
            {
                actor->OnFrameRender();
            }
        }
    }

    /**
     * Others
     *
     * AddActor: Adds an actor to the system.
     *
     * @param actor The actor to add.
     */
    void ActorSystem::AddActor(Actor* actor) 
    {
        _actors.push_back(actor);
    }

    /**
     * RemoveActor: Removes an actor from the system.
     *
     * @param actor The actor to remove.
     */
    void ActorSystem::RemoveActor(Actor* actor) 
    {
        _actors.erase(std::remove(_actors.begin(), _actors.end(), actor), _actors.end());
    }

    /**
     * GetActors: Gets a list of all actors in the system.
     *
     * @return A vector of all actors in the system.
     */
    std::vector<Actor*> ActorSystem::GetActors() 
    {
        return _actors;
    }
} // namespace RMC::Systems
