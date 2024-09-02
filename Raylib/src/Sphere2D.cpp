#include "Sphere2D.h"
#include "Actor2D.h"
#include <raylib.h>
#include "AudioSystem.h"
#include <iostream>

namespace RMC::rBitrage 
{
        
    Sphere2D::Sphere2D(Game& game) : Actor2D(game, "Ball01") { 
        _velocity = {0, 0, 0};
    }

    Sphere2D::~Sphere2D()
    {
    }

    void Sphere2D::OnFixedUpdate(float fixedDeltaTime)
    {
        Actor2D::OnFixedUpdate(fixedDeltaTime);
    }

    void Sphere2D::OnFrameUpdate(float deltaTime)
    {
        Actor2D::OnFrameUpdate(deltaTime);

        _transformation.Position.x += _velocity.x * deltaTime;
        _transformation.Position.y += _velocity.y * deltaTime;

        const float minX = _game.world.GetMin().x;
        const float maxX = _game.world.GetMax().x;
        const float minY = _game.world.GetMin().y;
        const float maxY = _game.world.GetMax().y;

        bool hasChangedDirection = false;
        if (_velocity.x < 0 && _transformation.Position.x - _size.x/2 <= minX)
        {
            _velocity.x *= -1;
            hasChangedDirection = true;
        }
            
        else if (_velocity.x > 0 && _transformation.Position.x + _size.x/2 >= maxX)
        {
            _velocity.x *= -1;
            hasChangedDirection = true;
        }
         
        if (_velocity.y < 0 && _transformation.Position.y - _size.y/2 <= minY)
        {
            _velocity.y *= -1;
            hasChangedDirection = true;
        }
            
        else if (_velocity.y > 0 && _transformation.Position.y + _size.y/2 >= maxY)
        {
            _velocity.y *= -1;
            hasChangedDirection = true;
        }

        if (hasChangedDirection) {
            if (_game.HasSystem<AudioSystem>())
            {
                _game.GetSystem<AudioSystem>()->PlaySound("Hit01");
            }
        }
    }

    void Sphere2D::OnFrameRender()
    {
        Actor2D::OnFrameRender();
    }


    Vector3 Sphere2D::GetVelocity() const 
    {
        return _velocity;
    }

    void Sphere2D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}