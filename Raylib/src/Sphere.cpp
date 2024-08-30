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

    _position.x += _velocity.x * deltaTime;
    _position.y += _velocity.y * deltaTime;

    if (_position.x + _size.x/2 >= GetScreenWidth() || _position.x - _size.x <= 0)
        _velocity.x *= -1;

    if (_position.y + _size.y >= GetScreenHeight() || _position.y - _size.y <= 0)
        _velocity.y *= -1;
}

void Sphere::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
{
    Actor::OnFrameRender(frameRenderLayer);
}


Vector3 Sphere::GetVelocity() const 
{
    return _velocity;
}

void Sphere::SetVelocity(const Vector3& velocity) 
{
    _velocity = velocity;
}