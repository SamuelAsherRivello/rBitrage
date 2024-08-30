#include "client/rBitrage/systems/PhysicsSystem.h"

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
        for (Actor* otherActor : _game.GetActors())
        {
            if (actor == otherActor) continue;
            if (CheckCollisionRecs(actor->GetBounds().ToRectangle(), otherActor->GetBounds().ToRectangle()))
            {
                return true; // collision detected
            }
        }
        return false; // no collisions found
    }

}
