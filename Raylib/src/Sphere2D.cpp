#include "Sphere2D.h"
#include "Actor2D.h"
#include <raylib.h>
#include "AudioSystem.h"
#include <iostream>
using namespace RMC::rBitrage;

Sphere2D::Sphere2D(Game& game) : Actor2D(game, "src/assets/images/itch.io/projectTemplate/Ball01.png") { 
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

    bool hasChangedDirection = false;
    if (_transformation.Position.x + _size.x/2 >= GetScreenWidth() || _transformation.Position.x - _size.x <= 0)
    {
        _velocity.x *= -1;
        hasChangedDirection = true;
    }
     

    if (_transformation.Position.y + _size.y >= GetScreenHeight() || _transformation.Position.y - _size.y <= 0)
    {
         _velocity.y *= -1;
         hasChangedDirection = true;
    }

    if(hasChangedDirection)
    {
        if (_game.HasSystem<AudioSystem>())
        {
            _game.GetSystem<AudioSystem>()->PlaySound2("Hit01");
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