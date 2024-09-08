#include "client/rBitrageDemos/actors/Ball3D.h"

namespace RMC::rBitrage 
{
        
    Ball3D::Ball3D(Game& game) : Shape3D(game, new SphereShapeData3D) { 
        _velocity = {0, 0, 0};

        //TODO: I'd like "Actor.cpp" to set once to the value that is 'whatever is the child class'
        SetName("Ball3D");
    }

    Ball3D::~Ball3D()
    {
    }

    void Ball3D::OnFrameUpdate(float deltaTime)
    {
        Shape3D::OnFrameUpdate(deltaTime);
        _transformation.Position.x += _velocity.x * deltaTime;
        _transformation.Position.y += _velocity.y * deltaTime;
        _transformation.Position.z += _velocity.z * deltaTime;

        const float minX = _game.world.GetMin().x;
        const float maxX = _game.world.GetMax().x;
        const float minY = _game.world.GetMin().y;
        const float maxY = _game.world.GetMax().y;
        const float minZ = _game.world.GetMin().z;
        const float maxZ = _game.world.GetMax().z;

        bool hasChangedDirection = false;

        //x
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
         
        //y
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

        //z
        if (_velocity.z < 0 && _transformation.Position.z - _size.z/2 <= minZ)
        {
            _velocity.z *= -1;
            hasChangedDirection = true;
        }
            
        else if (_velocity.z > 0 && _transformation.Position.z + _size.z/2 >= maxZ)
        {
            _velocity.z *= -1;
            hasChangedDirection = true;
        }


        if (hasChangedDirection) {
            if (_game.HasSystem<AudioSystem>())
            {
               //too noisy _game.GetSystem<AudioSystem>()->PlaySound("Hit01");
            }
        }
    }

    Vector3 Ball3D::GetVelocity() const 
    {
        return _velocity;
    }

    void Ball3D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}