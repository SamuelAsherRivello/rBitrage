#pragma once
#include <raylib.h>
#include "Actor2D.h"

namespace RMC::rBitrage 
{
    class OrbitPlayer : public Actor2D
    {
        public:

            //
            OrbitPlayer(Game& game);
            ~OrbitPlayer(); 

            //
            void OnFixedUpdate(float fixedDeltaTime) override;
            void OnFrameUpdate(float deltaTime) override;
            void OnFrameRender() override;

            Vector3 GetOrbitCenter() const;
            void SetOrbitCenter(const Vector3& orbitCenter);

        private:
            Vector3 _orbitCenter;
            float _velocityAngular; 
            const float _accelerationAngularInputMax = 10;
            float _accelerationAngularInput;
            float _accelerationAngularFriction;
            float _orbitRadius;
        };
}
