#pragma once
#include <iostream>
#include "client/rBitrage/actors/Sprite2D.h"
#include "client/rBitrage/systems/InputSystem.h"
#include "client/rBitrage/systems/AudioSystem.h"

namespace RMC::rBitrage 
{
    class OrbitPlayer : public Sprite2D
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
            const float _accelerationAngularInputMax = 5;
            float _accelerationAngularInput;
            float _accelerationAngularFriction;
            float _orbitRadius;
        };
}
