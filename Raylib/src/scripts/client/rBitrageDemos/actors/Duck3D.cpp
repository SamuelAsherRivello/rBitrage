#include "client/rBitrageDemos/actors/Duck3D.h"

namespace RMC::rBitrage 
{
    Duck3D::Duck3D (Game& game) 
        : Model3D 
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
        Actor3D::OnFrameUpdate(deltaTime);

        //MOVE
        _transform.Position.x += (GetVelocity().x * deltaTime);
        _transform.Position.y += (GetVelocity().y * deltaTime);
        _transform.Position.z += (GetVelocity().z * deltaTime);

        //TEMP
        _transform.Rotation.y += 1.0f * deltaTime;
    }

}