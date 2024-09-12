#include "client/rBitrageDemos/actors/Ball2D.h"

namespace RMC::rBitrage 
{
        
    Ball2D::Ball2D(Game& game, const char *assetKey) : Projectile2D(game, assetKey) { 
    }

    Ball2D::~Ball2D()
    {
    }

    void Ball2D::OnFrameUpdate(float deltaTime)
    {
        Projectile2D::OnFrameUpdate(deltaTime);

        const float minX = _game.world.GetMin().x;
        const float maxX = _game.world.GetMax().x;
        const float minY = _game.world.GetMin().y;
        const float maxY = _game.world.GetMax().y;
        const Vector3 size = GetBounds().GetSize();

        Vector3 velocity = GetVelocity();

        bool hasChangedDirection = false;
        if (velocity.x < 0 && _transform.Position.x - size.x/2 <= minX)
        {
            velocity.x *= -1;
            hasChangedDirection = true;
        }
            
        else if (velocity.x > 0 && _transform.Position.x + size.x/2 >= maxX)
        {
            velocity.x *= -1;
            hasChangedDirection = true;
        }
         
        if (velocity.y < 0 && _transform.Position.y - size.y/2 <= minY)
        {
            velocity.y *= -1;
            hasChangedDirection = true;
        }
            
        else if (velocity.y > 0 && _transform.Position.y + size.y/2 >= maxY)
        {
            velocity.y *= -1;
            hasChangedDirection = true;
        }

        if (hasChangedDirection) {
            SetVelocity(velocity);
            if (_game.HasSystem<AudioSystem>())
            {
                _game.GetSystem<AudioSystem>()->PlaySound("Hit01");
            }
        }
    }

}