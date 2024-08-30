#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"

namespace RMC::ProjectTemplate 
{
    class DebugSystem : public System 
    {
        public:
            DebugSystem(Game& game);
            void OnInitialize() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

        private:
    };

} 
