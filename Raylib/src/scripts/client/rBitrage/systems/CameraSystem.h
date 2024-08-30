#pragma once
#include "client/rBitrage/actors/Actor.h"
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/CameraSystemMode.h"
#include <raylib.h>
#include <optional>

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
            std::optional<Actor*> _targetActor; 

    };

} 