#include "Actor.h"
#include <raylib.h>
#include <iostream>


Actor::Actor(Game& game, const char *fileName, const FrameRenderLayer& frameRenderLayer) : _game (game) {

    _fileName = fileName;
    _frameRenderLayer = frameRenderLayer;
    SetPosition({0,0,0});
    SetSize({100, 100, 0});
}

Actor::~Actor() {
      if (_texture.id != 0) { // Check if texture is valid
        std::cout << "Unloading texture with ID: " << _texture.id << std::endl;
        UnloadTexture(_texture);
        _texture.id = 0; // Mark texture as invalid
    } else {
        std::cout << "Texture is not valid, skipping UnloadTexture." << std::endl;
    }
    std::cout << "Exiting Actor destructor" << std::endl;
}

void Actor::OnInitialize() {
}


void Actor::OnFixedUpdate(float deltaTime) {
}

void Actor::OnFrameUpdate(float deltaTime) {
}

void Actor::OnFrameRender() {

    if (_texture.width == 0) 
    {
        return;
    }

    DrawTexturePro(
        _texture, 
        {0, 0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)}, 
        {_transformation.Position.x, _transformation.Position.y, static_cast<float>(_texture.width), static_cast<float>(_texture.height)},
        {static_cast<float>(_texture.width)/2, static_cast<float>(_texture.height)/2},
        _transformation.Rotation.z, 
        WHITE);
    
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

    if (_fileName == NULL)
    {
        return;
    }
    Image image = LoadImage(_fileName);
    ImageResize(&image, _size.x, _size.y); 
    _texture = LoadTextureFromImage(image); 

}

Rectangle Actor::GetBounds() const  
{
    return Rectangle{_transformation.Position.x - _size.x/2, _transformation.Position.y - _size.y/2, _size.x, _size.y};
}

FrameRenderLayer Actor::GetFrameRenderLayer() const  
{
    return _frameRenderLayer;
}