#include "client/rBitrage/actors/Cube3D.h"

namespace RMC::rBitrage 
{
    Cube3D::Cube3D (Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor3D (game, assetKey, frameRenderLayer)
    {

    }

    Cube3D::~Cube3D() 
    {
        
    }

    void Cube3D::OnFrameRender() {

        Actor3D::OnFrameRender();

        // TODO: Use transform.scale instead of size here (and also in 2d?)
        //NOTE: I **think** that size is relative to asset an scale is relative to world unites and you need both. Yes?
        DrawCubeV(_transformation.Position, _size, WHITE);
        DrawCubeWiresV(_transformation.Position, _size, BLACK);

    }

    void Cube3D::SetSize(const Vector3& size) 
    {
        Actor::SetSize(size);

        //load 3d

    }
}