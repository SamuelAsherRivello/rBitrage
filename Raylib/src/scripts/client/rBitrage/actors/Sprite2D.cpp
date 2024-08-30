#include "client/rBitrage/actors/Sprite2D.h"

namespace RMC::rBitrage 
{
    Sprite2D::Sprite2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor2D (game, assetKey, frameRenderLayer)
    {
        //TODO: Remove this? I call this **Again** here eventhough parent does it
        // just to trigger building the texture. I don't like forcing a size. Use image size?
        
        SetSize(GetSize());
    }

    Sprite2D::~Sprite2D() 
    {
        if (_texture.id != 0) 
        { // Check if texture is valid
            std::cout << "Unloading texture with ID: " << _texture.id << std::endl;
            UnloadTexture(_texture);
            _texture.id = 0; // Mark texture as invalid
        } else 
        {
            std::cout << "Texture is not valid, skipping UnloadTexture." << std::endl;
        }
        std::cout << "Exiting Actor destructor" << std::endl;
    }

    void Sprite2D::OnFrameRender() {

        Actor2D::OnFrameRender();

        if (strlen(_assetKey) == 0)
        {
            return;
        }

        unsigned char opacity = 255 * GetOpacity();

              std::cout << "drawing image " << _texture.width << " and " << _texture.height << " for " << _assetKey << std::endl;
        DrawTexturePro
            (
                _texture, 
                {0, 0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)}, 
                {_transformation.Position.x, _transformation.Position.y, static_cast<float>(_texture.width), static_cast<float>(_texture.height)},
                {Vector2Multiply({static_cast<float>(_texture.width), static_cast<float>(_texture.height)}, Utilities::ToVector2(_pivot))},
                _transformation.Rotation.z, 
                CLITERAL(Color){ 255, 255, 255, opacity }
            );
        
    }

    void Sprite2D::SetSize(const Vector3& size) 
    {
        Actor2D::SetSize(size);

        if (strlen(_assetKey) == 0)
        {
            std::cout << "SetSize() failed per _fileName for " << _assetKey << std::endl;
            return;
        }

        if (!_game.HasSystem<AssetLoaderSystem>())
        {
            std::cout << "SetSize() failed per LoaderSystem for " << _assetKey << std::endl;
            return;
        }

        Image image = _game.GetSystem<AssetLoaderSystem>()->GetAssetAsImage<Image>(_assetKey);

        if (image.width == 0)
        {
            std::cout << "SetSize() failed per image for " << _assetKey << std::endl;
            return;
        }

        std::cout << "loading image " << Utilities::ToString(image.width) << " and " << image.height << " for " << _assetKey << std::endl;
        ImageResize(&image, size.x, size.y);
        _texture = LoadTextureFromImage(image);

    }
}