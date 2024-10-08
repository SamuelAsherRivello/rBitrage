#include "client/rBitrage/actors/Cube3D.h"
#include "Cube3D.h"

namespace RMC::rBitrage 
{
    Cube3D::Cube3D (Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor3D (game, assetKey, frameRenderLayer)
    {

    }

    Cube3D::~Cube3D() 
    {
        
    }

    void Cube3D::OnFrameRender(const FrameRenderLayer& frameRenderLayer) {

        Actor3D::OnFrameRender(frameRenderLayer);

        // TODO: Use transform.scale instead of size here (and also in 2d?)
        //NOTE: I **think** that size is relative to asset an scale is relative to world unites and you need both. Yes?
        DrawCubeV(_transform.Position, GetBoundsLocal().GetSize(), WHITE);
        DrawCubeWiresV(_transform.Position, GetBoundsLocal().GetSize(), BLACK);

    }

}