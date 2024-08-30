#include "client/rBitrage/actors/Model3D.h"

namespace RMC::rBitrage 
{
    Model3D::Model3D (Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor3D (game, assetKey, frameRenderLayer)
    {
        //TODO: I call this **Again** eventhough parent does it
        // just to trigger building the texture. Can I remove this?
        SetSize({1, 1, 1}); //Good default for all 3D
    }

    Model3D::~Model3D() 
    {
        
    }

    void Model3D::OnFrameRender() {

        Actor3D::OnFrameRender();

        // TODO: Use transform.scale instead of size here (and also in 2d?)
        //NOTE: I **think** that size is relative to asset an scale is relative to world unites and you need both. Yes?
        DrawCubeV(_transformation.Position, _size, WHITE);
        DrawCubeWiresV(_transformation.Position, _size, BLACK);

    }

    void Model3D::SetSize(const Vector3& size) 
    {
        Actor::SetSize(size);

        //load 3d

    }
}