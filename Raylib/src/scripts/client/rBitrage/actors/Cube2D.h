#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Cube2D.h"
#include "client/rBitrage/actors/Sprite2D.h"
#include "client/rBitrage/systems/InputSystem.h"
#include "client/rBitrage/systems/PhysicsSystem.h"
#include <iostream>
namespace RMC::rBitrage 
{
    class Cube2D : public Sprite2D
    {
    public:
        Cube2D(Game& game);
        ~Cube2D(); 
        void OnFixedUpdate(float fixedDeltaTime) override;
        void OnFrameUpdate(float deltaTime) override;
        void OnFrameRender(const FrameRenderLayer& frameRenderLayer) override;
    

    private:
        Vector3 _velocityLinear;
        Vector3 _velocityAngular;
        bool _isCollision;
    };

}