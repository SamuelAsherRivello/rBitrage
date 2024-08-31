#pragma once
#include <raylib.h>
#include "Actor2D.h"
namespace RMC::rBitrage 
{
    class Cube2D : public Actor2D
    {
    public:
        Cube2D(Game& game);
        ~Cube2D(); 
        void OnFixedUpdate(float fixedDeltaTime) override;
        void OnFrameUpdate(float deltaTime) override;
        void OnFrameRender() override;
    

    private:
        Vector3 _velocityLinear;
        Vector3 _velocityAngular;
        bool _isCollision;
    };

}