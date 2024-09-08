#include "client/rBitrage/actors/Projectile3D.h"

namespace RMC::rBitrage 
{
        
    Projectile3D::Projectile3D(Game& game, const char *assetKey) : Model3D(game, assetKey) { 
        _velocity = {0, 0, 0};
    }

    Projectile3D::~Projectile3D()
    {
    }

    void Projectile3D::OnFrameUpdate(float deltaTime)
    {
        Model3D::OnFrameUpdate(deltaTime);

        _transformation.Position.x += _velocity.x * deltaTime;
        _transformation.Position.y += _velocity.y * deltaTime;
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