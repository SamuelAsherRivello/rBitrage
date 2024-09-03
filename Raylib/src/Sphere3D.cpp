#include "Sphere3D.h"
#include "Actor3D.h"
#include <raylib.h>
#include "AudioSystem.h"
#include <iostream>

namespace RMC::rBitrage 
{
        
    Sphere3D::Sphere3D(Game& game) : Actor3D(game, "Ball01") { 
        _velocity = {0, 0, 0};

        //TODO: I'd like "Actor.cpp" to set once to the value that is 'whatever is the child class'
        SetName("Sphere3D");
    }

    Sphere3D::~Sphere3D()
    {
    }

    void Sphere3D::OnFixedUpdate(float fixedDeltaTime)
    {
        Actor3D::OnFixedUpdate(fixedDeltaTime);
          std::cout << "Sphere3D::OnFixedUpdate()" << std::endl;
    }

    void Sphere3D::OnFrameUpdate(float deltaTime)
    {
        Actor3D::OnFrameUpdate(deltaTime);

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

    void Sphere3D::OnFrameRender()
    {
        Actor3D::OnFrameRender();

std::cout << "4, ActorSystem::OnFrameRender 2" << std::endl;
    }


    Vector3 Sphere3D::GetVelocity() const 
    {
        return _velocity;
    }

    void Sphere3D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}