#pragma once
#include "client/rBitrage/actors/Actor3D.h"


namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Cube3D : public Actor3D
    {
    public:
        Cube3D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);
        virtual ~Cube3D();

        void OnFrameRender(const FrameRenderLayer &frameRenderLayer) override;

    protected:
        const char *_assetKey;
    };

}