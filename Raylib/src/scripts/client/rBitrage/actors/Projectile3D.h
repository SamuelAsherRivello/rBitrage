#pragma once
#include <raylib.h>
#include <iostream>
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/actors/Model3D.h"
#include "client/rBitrage/mixins/Mixins.h"

namespace RMC::rBitrage 
{
    class Projectile3D : public Model3D
    {
        public:

            //
            Projectile3D(Game& game, std::unique_ptr<ModelData3D>);
            ~Projectile3D(); 

            //
            void OnFrameUpdate(float fixedDeltaTime) override;

            //
            Vector3 GetVelocity() const;
            void SetVelocity(const Vector3& velocity);

        private:
            Vector3 _velocity; 
            //std::unique_ptr<PositionVelocityBoundsMixin> _positionVelocityBoundsMixin;
        };
}
