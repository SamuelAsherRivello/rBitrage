#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"
#include <optional>
#include "FrameRenderLayer.h"

namespace RMC::rBitrage 
{
    class CameraSystem : public System 
    {
        public:
            CameraSystem(Game& game);
            void OnInitialize() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            //
            void SetTargetActor(Actor* targetActor);
            Actor* GetTargetActor();

            //Fields
            Camera2D camera2D;
        


        private:
            std::optional<Actor*> _targetActor; // Add the semicolon here!
    };

} 