#pragma once
#include "client/rBitrage/actors/Actor3D.h"


namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Model3D : public Actor3D
    {
    public:
        Model3D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);
        virtual ~Model3D();

        void OnFrameRender() override;
        void SetSize(const Vector3 &size) override;

    protected:
        const char *_assetKey;
    };

}