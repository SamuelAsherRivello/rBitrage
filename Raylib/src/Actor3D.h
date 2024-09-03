
#pragma once
#include <raylib.h>
#include "Actor.h"
#include "Game.h"
#include "FrameRenderLayer.h"
#include "Transform.h"

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Actor3D : public Actor
    {
    public:
        Actor3D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);
        virtual ~Actor3D();

        void OnInitialize() override;
        void OnFixedUpdate(float fixedDeltaTime) override;
        void OnFrameUpdate(float deltaTime) override;
        void OnFrameRender() override;
        void SetSize(const Vector3 &size) override;

    protected:
        const char *_assetKey;
    };

}