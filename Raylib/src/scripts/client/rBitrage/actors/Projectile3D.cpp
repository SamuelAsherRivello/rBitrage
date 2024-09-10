#include "client/rBitrage/actors/Projectile3D.h"

namespace RMC::rBitrage 
{
        
    Projectile3D::Projectile3D(Game& game, std::unique_ptr<ModelData3D> modelData3D) : 
        Model3D(game, std::move(modelData3D))
    { 
        _velocity = {0, 0, 0};

        /*
        ,
        _positionVelocityBoundsMixin(std::make_unique<PositionVelocityBoundsMixin>(*this, &_velocity))
        */
        
    }

    Projectile3D::~Projectile3D()
    {
    }

    void Projectile3D::OnFrameUpdate(float deltaTime)
    {
        Model3D::OnFrameUpdate(deltaTime);

        //Move
        _transform.Position.x += _velocity.x * deltaTime;
        _transform.Position.y += _velocity.y * deltaTime;
        _transform.Position.z += _velocity.z * deltaTime;

        //Checkbounds (Experimental "Mixin" API)
        //_positionVelocityBoundsMixin->OnFrameUpdate(deltaTime);


    }

    Vector3 Projectile3D::GetVelocity() const 
    {
        return _velocity;
    }

    void Projectile3D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}