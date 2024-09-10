#pragma once
#include "client/rBitrage/actors/Projectile3D.h"


namespace RMC::rBitrage 
{
    class Duck3D : public Projectile3D
    {
        public:
            Duck3D(Game& game);
            virtual ~Duck3D();
            void OnFrameUpdate(float deltaTime) override;

        protected:
    };

}