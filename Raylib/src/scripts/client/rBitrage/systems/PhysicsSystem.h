#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/actors/Actor.h"

namespace RMC::rBitrage {

    class PhysicsSystem : public System {
        public:
            PhysicsSystem(Game& game);
            bool IsCollision(Actor* actor);

        protected:
            void OnFrameUpdate(float deltaTime);
            void OnFixedUpdate(float fixedDeltaTime);
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer);

    };
}