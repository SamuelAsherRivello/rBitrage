#pragma once
#include <raylib.h>
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/systems/InputSystem.h"

namespace RMC::rBitrage 
{
    class ApplicationSystem : public System 
    {
        public:
            ApplicationSystem(Game& game);
            void OnInitialize() override;
            void OnInitialized() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            bool RaylibWindowShouldClose();
            void RaylibCloseWindow();

        private:
    };

} 
