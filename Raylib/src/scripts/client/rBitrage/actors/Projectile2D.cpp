#include "client/rBitrage/actors/Projectile2D.h"

namespace RMC::rBitrage 
{
        
    Projectile2D::Projectile2D(Game& game, const char *assetKey) : Sprite2D(game, assetKey) { 
        _velocity = {0, 0, 0};
    }

    Projectile2D::~Projectile2D()
    {
    }

    void Projectile2D::OnFrameUpdate(float deltaTime)
    {
        Sprite2D::OnFrameUpdate(deltaTime);

        _transformation.Position.x += _velocity.x * deltaTime;
        _transformation.Position.y += _velocity.y * deltaTime;
    }

    Vector3 Projectile2D::GetVelocity() const 
    {
        return _velocity;
    }

    void Projectile2D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}