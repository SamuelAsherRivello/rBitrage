#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/systems/CameraSystem.h"
#include "client/rBitrage/types/CameraSystemMode.h"
#include "client/rBitrage/actors/Actor.h"

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
            void DrawCrosshairsAtCenterRectangle(Rectangle rectangle, float scale, float thick, Color color);
            void DrawScreenBounds();

            void DrawWorldBounds();

            //
            void DrawActorBounds(Actor* actor);
            void DrawActorPivot(Actor *actor);
            void DrawActorCenter(Actor *actor);

        private:
            Color _actorColor = ORANGE;
            Color _worldColor = BLUE;
            Color _screenColor = GREEN;
            float _centerRadius = 10;
            float _pivotRadius = 10;
            float _worldStroke = 10;
            float _screenStroke = 4;
    };

} 
