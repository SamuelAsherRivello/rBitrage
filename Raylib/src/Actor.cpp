#include "Actor.h"
#include <raylib.h>
#include <iostream>


Actor::Actor(Game& game, const FrameRenderLayer& frameRenderLayer) : _game (game) 
{
    _frameRenderLayer = frameRenderLayer;
    SetPosition({0,0,0});
    SetSize({100, 100, 0});
}

Actor::~Actor() 
{
 
}

void Actor::OnInitialize() 
{
}


void Actor::OnFixedUpdate(float fixedDeltaTime) 
{
}

void Actor::OnFrameUpdate(float deltaTime) 
{
}

void Actor::OnFrameRender() 
{

    
}

Vector3 Actor::GetPosition() const 
{
    return _transformation.Position;
}

void Actor::SetPosition(const Vector3& position) 
{
    _transformation.Position = position;
}

Vector3 Actor::GetRotation() const 
{
    return _transformation.Rotation;
}

void Actor::SetRotation(const Vector3& position) 
{
    _transformation.Rotation = position;
}

Vector3 Actor::GetSize() const 
{
    return _size;
}

void Actor::SetSize(const Vector3& size) 
{
    _size = size;

}

Bounds Actor::GetBounds() const  
{
    return {
                {_transformation.Position.x, _transformation.Position.y, _transformation.Position.z}, 
                {_size.x, _size.y, _size.z}
            };
}

FrameRenderLayer Actor::GetFrameRenderLayer() const  
{
    return _frameRenderLayer;
}