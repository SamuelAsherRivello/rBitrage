#pragma once

namespace RMC::rBitrage
{

    class Game;

    class ILifecycle {
        public:
            virtual void OnInitialize() = 0;
            virtual void OnInitialized() = 0;
            virtual void OnFixedUpdate(float fixedDeltaTime) = 0;
            virtual void OnFrameUpdate(float deltaTime) = 0;
            virtual void OnFrameRender(const FrameRenderLayer& frameRenderLayer) = 0;

    };

}