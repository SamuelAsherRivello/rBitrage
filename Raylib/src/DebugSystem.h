#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"

namespace RMC::rBitrage 
{
    class DebugSystem : public System 
    {
        public:
            DebugSystem(Game& game);
            void OnInitialize() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            void DrawWorldSizeHalf();
            void DrawScreenSizeHalf();
            void DrawScreenBounds();

            void DrawWorldBounds();

        private:
            Color _worldColor = BLUE;
            Color _screenColor = GREEN;

            float _worldStroke = 10;
            float _screenStroke = 4;
    };

} 
