#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"
#include <optional>
#include "FrameRenderLayer.h"
#include "CameraSystemMode.h"

namespace RMC::rBitrage 
{

    class CameraSystem : public System 
    {
     

        public:
       

            CameraSystem(Game& game, CameraSystemMode cameraSystemMode);
            void OnInitialize() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            //
            void SetTargetActor(Actor* targetActor);
            Actor* GetTargetActor();

            //Fields
            Camera2D camera2D;
            Camera3D camera3D;
            CameraSystemMode cameraSystemMode = CameraSystemMode::Cam2DAnd3D;
        


        private:
            std::optional<Actor*> _targetActor; // Add the semicolon here!

    };

} 