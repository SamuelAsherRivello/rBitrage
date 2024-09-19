#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/systems/InputSystem.h"

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
            void OnInitialized() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            void DrawWorldSizeHalf();
            void DrawScreenSizeHalf();
            void RenderCrosshairsAtRectangleCenter(Rectangle rectangle, float scale, float thick, Color color);
            void RenderCrosshairsAtRectangleCenter(Rectangle rectangle, float scale, float thick, Color color, const char *label);
            void RenderBoxAtRectangle(Rectangle rectangle, float thick, Color color);
            void RenderBoxAtRectangle(Rectangle rectangle, float thick, Color color, const char * label);
            void RenderCircleAtPoint(Vector2 point, float radius, Color color);
            void RenderCircleAtPoint(Vector2 point, float radius, Color color, const char *label);
            void DrawScreenBounds();
            void DrawWorldBounds();

            void DrawActor2D(Actor *actor);

            void DrawActorCenterAtGlobal2D(Actor *actor);

            void DrawActorExtentsAtGlobal3D(Actor *actor);

            //
            void DrawActorBoundsAtGlobal2D(Actor* actor);
            void DrawActorPositionAtGlobal2D(Actor *actor);
            void DrawActorPivotAtGlobal2D(Actor *actor);

        private:
            Color _actorColorPrimary = ORANGE;
            Color _actorColorSecondary = WHITE;
            Color _worldColor = BLUE;
            Color _screenColor = GREEN;
            float _centerRadius = 10;
            float _pivotRadius = 10;
            float _worldStroke = 5;
            float _screenStroke = 2.5;
            float _crosshairScale = 1.0f;
            //
            Vector2 _fontPositionOffset = {10, 10};
            float _labelFontSize = 20; 
    };

} 
