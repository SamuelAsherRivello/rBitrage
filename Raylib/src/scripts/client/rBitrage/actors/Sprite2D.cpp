#include "client/rBitrage/actors/Sprite2D.h"

namespace RMC::rBitrage 
{
    //TODO: Is there a better way to do a null vector?
    const Vector3 Vector3Null = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };

    Sprite2D::Sprite2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor2D (game, assetKey, frameRenderLayer)
    {
        ResizeAsset();
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
        //
        const auto scale = GetScale();
        const auto position = GetPosition();
        const auto bounds = GetBounds();
        const auto size = bounds.GetSize();
        const auto pivot = bounds.GetPivot();

        DrawTexturePro
            (
                _texture, 
                {0, 0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)}, 
                {position.x, position.y, size.x , size.y },
                {pivot.x, pivot.y},
                _transform.Rotation.z, 
                CLITERAL(Color){ 255, 255, 255, opacity }
            );
        
    }

    void Sprite2D::ResizeAsset() 
    {
        ResizeAsset(Vector3Null);
    }

    void Sprite2D::ResizeAsset(const Vector3& size) 
    {
        Actor2D::ResizeAsset(size);

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

        //TODO: Find better 'ignore me' value than -1/-1/-1 since that's too common
        if (Vector3Equals(size, Vector3Null))
        {
            //TODO: Resize to original size. This may not be needed since we load fresh right before
            //but we may move where the load happens, so keep this here?
            ImageResize(&image, image.width, image.height);  
        }
        else
        {
            ImageResize(&image, size.x, size.y);  
        }

        _texture = LoadTextureFromImage(image);

        //Always set the bounds based on the new asset size
        auto v = Utilities::ToVector3({(float)_texture.width, (float)_texture.height});
        GetBounds().SetSize(v);
    }
}