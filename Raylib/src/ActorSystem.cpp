#include <raylib.h>
#include <iostream>
#include <memory>
#include "Game.h"
#include "ActorSystem.h"

namespace RMC::rBitrage
{
    void ActorSystem::OnInitialize()
    {
        for (auto& actor : _actors)
        {
            actor->OnInitialize();
        }
    }

    void ActorSystem::OnFixedUpdate(float fixedDeltaTime)
    {
        for (auto& actor : _actors)
        {
            actor->OnFixedUpdate(fixedDeltaTime);
        }
    }

    void ActorSystem::OnFrameUpdate(float deltaTime)
    {
        for (auto& actor : _actors)
        {
            actor->OnFrameUpdate(deltaTime);
        }
    }

    void ActorSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
        for (auto& actor : _actors)
        {
            if (actor->GetFrameRenderLayer() == frameRenderLayer)
            {
                actor->OnFrameRender();
            }
        }
    }

    void ActorSystem::AddActor(std::unique_ptr<Actor> actor)
    {
        _actors.emplace_back(std::move(actor));
    }

    bool ActorSystem::RemoveActor(std::unique_ptr<Actor> actor)
    {
        for (auto& a : _actors)
        {
            if (a.get() == actor.get())
            {
                _actors.erase(std::remove(_actors.begin(), _actors.end(), actor), _actors.end());
                return true;
            }
        }

        return false;
    }

    bool ActorSystem::HasActor(std::unique_ptr<Actor> actor)
    {
        for (const auto& a : _actors)
        {
            if (a.get() == actor.get())
            {
                return true;
            }
        }

        return false;
    }
    
    std::vector<std::unique_ptr<Actor>> ActorSystem::GetActors()
    {
        return _actors;
    }
} // namespace RMC::Systems
