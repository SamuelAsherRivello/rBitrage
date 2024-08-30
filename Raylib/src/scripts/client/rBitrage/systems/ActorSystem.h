#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/actors/Actor.h"
#include <iostream>
#include <algorithm>


namespace RMC::rBitrage 
{
    class ActorSystem : public System 
    {
        public:
            ActorSystem(Game& game);

            std::vector<Actor*> GetActors();
            void AddActor(Actor *actor);
            void RemoveActor(Actor *actor);

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
