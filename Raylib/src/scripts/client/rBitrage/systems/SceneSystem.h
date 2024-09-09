#pragma once
#include <vector>
#include <memory>
//
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/actors/Actor.h"
#include "client/rBitrage/types/Scene.h"


namespace RMC::rBitrage 
{

    class SceneSystem : public System 
    {
        public:
            SceneSystem(Game& game);
            void OnInitialize() override;
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

            Scene* currentScene;

        private:
    };

} 
