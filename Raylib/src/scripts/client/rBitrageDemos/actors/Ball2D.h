#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Projectile2D.h"
#include "client/rBitrage/systems/AudioSystem.h"
#include "client/rBitrage/mixins/Mixins.h"
#include "client/rBitrage/types/Event.h"
#include <iostream>

namespace RMC::rBitrage 
{
    class Ball2D : public Projectile2D
    {
        public:

            //
            Ball2D(Game& game, const char *assetKey);
            ~Ball2D(); 

            //
            void OnFrameUpdate(float deltaTime) override;

            //
            Event OnBounce = Event();

        private:

            //Experimental: See class comment
            PositionVelocityBoundsMixin _mixin;
        
        };
}
