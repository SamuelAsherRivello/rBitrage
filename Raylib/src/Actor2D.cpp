#include "Actor2D.h"
#include "Actor.h"
#include <raylib.h>
#include <iostream>
#include <string>

namespace RMC::rBitrage 
{
    Actor2D::Actor2D(Game& game, const char *fileName, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, frameRenderLayer)
    {
        _fileName = fileName;

        //TODO: I call this **Again** eventhough parent does it
        // just to trigger building the texture. Can I remove this?
        SetSize({100, 100, 0});
    }

    Actor2D::~Actor2D() 
    {
        if (_texture.id != 0) { // Check if texture is valid
            std::cout << "Unloading texture with ID: " << _texture.id << std::endl;
            UnloadTexture(_texture);
            _texture.id = 0; // Mark texture as invalid
        } else {
            std::cout << "Texture is not valid, skipping UnloadTexture." << std::endl;
        }
        std::cout << "Exiting Actor destructor" << std::endl;
    }

    void Actor2D::OnInitialize() {
        Actor::OnInitialize();
    }


    void Actor2D::OnFixedUpdate(float fixedDeltaTime) 
    {
        Actor::OnFixedUpdate(fixedDeltaTime);
    }

    void Actor2D::OnFrameUpdate(float deltaTime) 
    {
        Actor::OnFrameUpdate(deltaTime);
    }

    void Actor2D::OnFrameRender() {

        Actor::OnFrameRender();

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

    void Actor2D::SetSize(const Vector3& size) 
    {
        Actor::SetSize(size);

        if (_fileName == NULL)
        {
            return;
        }

        std::string filePath = "src/assets/images/itch.io/projectTemplate/";
        filePath += _fileName;
        filePath += ".png";
        const char *filePathPtr = filePath.c_str();
        Image image = LoadImage(filePathPtr);
        ImageResize(&image, _size.x, _size.y); 
        _texture = LoadTextureFromImage(image); 

    }
}