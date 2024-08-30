#pragma once
#include <raylib.h>
#include "Game.h"

namespace RMC::ProjectTemplate {

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