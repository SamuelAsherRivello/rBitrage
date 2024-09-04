#pragma once

#include <raylib.h>
#include <iostream>
#include <memory>
#include <algorithm>
#include "System.h"
#include "Game.h"
#include "Actor.h"
#include "FrameRenderLayer.h"

namespace RMC::rBitrage 
{
    class ActorSystem : public System 
    {
        public:
            ActorSystem(Game& game);

            //
            std::vector<std::unique_ptr<Actor>> GetActors();
            void AddActor(std::unique_ptr<Actor> actor);
            bool RemoveActor(std::unique_ptr<Actor> actor);
            bool HasActor(std::unique_ptr<Actor> actor);
            //

        protected:
            void OnInitialize() override;
            void OnFixedUpdate(float deltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

      

        private:
            std::vector<std::unique_ptr<Actor>> _actors;
            

    };
}
