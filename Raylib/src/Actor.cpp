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

void Actor::OnFrameRender(const FrameRenderLayer& frameRenderLayer) {

    if (_frameRenderLayer != frameRenderLayer)
    {
        return;
    }
    DrawTexture(_texture, _position.x - _size.x/2, _position.y - _size.y/2, WHITE);
}

Vector3 Actor::GetPosition() const {
    return _position;
}

void Actor::SetPosition(const Vector3& position) {
    _position = position;
}

Vector3 Actor::GetSize() const {
    return _size;
}

void Actor::SetSize(const Vector3& size) {
    _size = size;
    Image image = LoadImage(_fileName);
    ImageResize(&image, _size.x, _size.y); 
    _texture = LoadTextureFromImage(image); 
}

Rectangle Actor::GetBounds() const  {
    return Rectangle{_position.x - _size.x/2, _position.y - _size.y/2, _size.x, _size.y};
}

FrameRenderLayer Actor::GetFrameRenderLayer() const  {
    return _frameRenderLayer;
}