#include "client/rBitrageDemos/actors/Duck3D.h"

namespace RMC::rBitrage 
{
    Duck3D::Duck3D (Game& game) 
        : Projectile3D 
        (
            game,
             std::make_unique<ModelData3D>
             (
                "DuckModel01", 
                "DuckTexture2D01",
                Vector3{0.1f, 0.1f, 0.1f},
                Color{WHITE}
            )
        )
    {

    }
        

    Duck3D::~Duck3D() 
    {
        
    }

    void Duck3D::OnFrameUpdate(float deltaTime) 
    {
        Projectile3D::OnFrameUpdate(deltaTime);
        _transform.Rotation.y += 1.0f * deltaTime;
    }

}