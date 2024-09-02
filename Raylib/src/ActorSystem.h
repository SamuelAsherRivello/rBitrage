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

            void AddActor(Actor* actor);
            std::vector<Actor*> GetActors();
            void RemoveActor(Actor* actor);

            bool HasActor(Actor *actor);

        protected:
            void OnInitialize() override;
            void OnFixedUpdate(float deltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;

        private:
            std::vector<Actor*> _actors;

    };
}
