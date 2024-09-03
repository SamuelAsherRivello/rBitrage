#pragma once
#include <raylib.h>
#include "Actor3D.h"

namespace RMC::rBitrage 
{
    class Sphere3D : public Actor3D
    {
        public:

            //
            Sphere3D(Game& game);
            ~Sphere3D(); 

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
