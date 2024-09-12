#pragma once
#include <raylib.h>
#include <iostream>
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/actors/Sprite2D.h"

namespace RMC::rBitrage 
{
    class Projectile2D : public Sprite2D
    {
        public:

            //
            Projectile2D(Game& game, const char *assetKey);
            ~Projectile2D(); 

            //
            void OnFrameUpdate(float fixedDeltaTime) override;

            Vector3& GetVelocity();

            //
            void SetVelocity(const Vector3& velocity);

        private:
            Vector3 _velocity; 
        };
}
