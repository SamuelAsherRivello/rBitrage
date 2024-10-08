#pragma once
#include <iostream>
#include <raylib.h>
#include "client/rBitrage/actors/Shape3D.h"
#include "client/rBitrage/systems/AudioSystem.h"
#include "client/rBitrage/mixins/Mixins.h"



namespace RMC::rBitrage 
{
    class Ball3D : public Shape3D
    {
        public:


            //
            Ball3D(Game& game);
            ~Ball3D(); 

            //
            void OnFrameUpdate(float deltaTime) override;

            Vector3& GetVelocity();
            void SetVelocity(const Vector3& velocity);

        private:
            Vector3 _velocity; 

            //Experimental: See class comment
            PositionVelocityBoundsMixin _mixin;
        };
}
