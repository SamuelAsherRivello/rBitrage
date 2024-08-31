#include "Sphere.h"
#include "Actor.h"
#include <raylib.h>
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include <iostream>

Sphere::Sphere(Game& game) : Actor(game, "src/assets/images/itch.io/projectTemplate/Ball01.png") { 
    _velocity = {0, 0, 0};
}

Sphere::~Sphere()
{
}

void Sphere::OnFixedUpdate(float fixedDeltaTime)
{
    Actor::OnFixedUpdate(fixedDeltaTime);
}

void Sphere::OnFrameUpdate(float deltaTime)
{
    Actor::OnFrameUpdate(deltaTime);

    _transformation.Position.x += _velocity.x * deltaTime;
    _transformation.Position.y += _velocity.y * deltaTime;

    if (_transformation.Position.x + _size.x/2 >= GetScreenWidth() || _transformation.Position.x - _size.x <= 0)
        _velocity.x *= -1;

    if (_transformation.Position.y + _size.y >= GetScreenHeight() || _transformation.Position.y - _size.y <= 0)
        _velocity.y *= -1;
}

void Sphere::OnFrameRender()
{
    Actor::OnFrameRender();
}


Vector3 Sphere::GetVelocity() const 
{
    return _velocity;
}

void Sphere::SetVelocity(const Vector3& velocity) 
{
    _velocity = velocity;
}