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

            //TODO: Change these 5 lines to 1 line. Workaround because of const??
            Bounds bounds1 = actor->GetBoundsGlobal();
            Bounds bounds2 = actor->GetBoundsGlobal();
            const Rectangle rectangle1 = bounds1.ToRectangle();
            const Rectangle rectangle2 = bounds2.ToRectangle();
            if (CheckCollisionRecs(rectangle1, rectangle2))
            {
                return true; // collision detected
            }
        }
        return false; // no collisions found
    }

}
