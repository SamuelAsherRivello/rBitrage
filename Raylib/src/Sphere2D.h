#pragma once
#include <raylib.h>
#include "Actor2D.h"

namespace RMC::rBitrage 
{
    class Sphere2D : public Actor2D
    {
        public:

            //
            Sphere2D(Game& game);
            ~Sphere2D(); 

            //
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender() override;

            //
            Vector3 GetVelocity() const;
            void SetVelocity(const Vector3& velocity);

        private:
            Vector3 _velocity; 
        };
}
