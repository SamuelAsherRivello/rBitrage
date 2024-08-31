#include "Actor2D.h"
#include "Actor.h"
#include "LoaderSystem.h"
#include <raylib.h>
#include <iostream>
#include <string>
#include <string.h>

namespace RMC::rBitrage 
{
    Actor2D::Actor2D(Game& game, const char *fileName, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, frameRenderLayer)
    {
        _assetKey = fileName;

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

        if (strlen(_assetKey) == 0)
        {
            std::cout << "SetSize() failed per _fileName for " << _assetKey << std::endl;
            return;
        }

        if (!_game.HasSystem<LoaderSystem>())
        {
            std::cout << "SetSize() failed per LoaderSystem for " << _assetKey << std::endl;
            return;
        }

        Image image = _game.GetSystem<LoaderSystem>()->GetAssetCopy<Image>(_assetKey);

        if (image.width == 0)
        {
            std::cout << "SetSize() failed per image for " << _assetKey << std::endl;
            return;
        }

        ImageResize(&image, size.x, size.y);
        _texture = LoadTextureFromImage(image);

    }
}