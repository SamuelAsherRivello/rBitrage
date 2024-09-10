#include "client/rBitrage/actors/Model3D.h"

namespace RMC::rBitrage 
{
    Model3D::Model3D (Game& game, std::unique_ptr<ModelData3D> modelData3D) 
        : Actor3D (game, "", FrameRenderLayer::Camera3D), 
        _modelData3D(modelData3D.get())
    {

        if (!_game.HasSystem<AssetLoaderSystem>())
        {
            return;
        }

        if (!_game.GetSystem<AssetLoaderSystem>()->HasAsset<Model>(_modelData3D->modelAssetKey))
        {
            return;
        }

        _model = _game.GetSystem<AssetLoaderSystem>()->GetAssetAsModel<Model>(_modelData3D->modelAssetKey);
        _texture2D = _game.GetSystem<AssetLoaderSystem>()->GetAssetAsTexture2D<Texture2D>(_modelData3D->textureAssetKey);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture2D;

        //TODO: Maybe make size FROM the model geometry. The make a new 'actor.Scale' that is user-settable.
        //SetSize(_modelData3D->scaleFactor); 
     
    }

    Model3D::~Model3D() 
    {
    }

    void Model3D::OnFrameUpdate(float deltaTime) 
    {
        Actor3D::OnFrameUpdate(deltaTime);
    }

    void Model3D::OnFrameRender() {
        Actor3D::OnFrameRender();

        if (Utilities::IsNullOrEmpty(_model)) 
        {
            //TODO: This if check does not work
            return;
        }
        _model.transform = MatrixRotateXYZ(_transform.Rotation);
        DrawModel(_model, _transform.Position, Utilities::ToVector3Average(_size).x, _modelData3D->color);
        
    }
}
      
