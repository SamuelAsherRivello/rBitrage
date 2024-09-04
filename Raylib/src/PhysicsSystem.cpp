#include <raylib.h>
#include "PhysicsSystem.h"
#include "Game.h"

namespace RMC::rBitrage 
{

    PhysicsSystem::PhysicsSystem(Game& game) : System(game)
    {
    }

    void PhysicsSystem::OnFixedUpdate(float fixedDeltaTime)
    {
    }

    void PhysicsSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
    }

    void PhysicsSystem::OnFrameUpdate(float deltaTime)
    {
    }

    
    bool PhysicsSystem::IsCollision(Actor* actor)
    {
        // for (auto otherActor : _game.GetActors())
        // {
        //     if (actor == otherActor.get()) continue;
        //     if (CheckCollisionRecs(actor->GetBounds().ToRectangle(), otherActor->GetBounds().ToRectangle()))
        //     {
        //         return true; // collision detected
        //     }
        // }
        return false; // no collisions found
    }

}
