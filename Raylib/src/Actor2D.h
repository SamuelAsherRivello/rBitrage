
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

    class Actor2D : public Actor
    {
    public:
        Actor2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
        virtual ~Actor2D();

        void OnInitialize() override;
        void OnFixedUpdate(float fixedDeltaTime) override;
        void OnFrameUpdate(float deltaTime) override;
        void OnFrameRender() override;
        void SetSize(const Vector3 &size) override;

    protected:
        const char *_assetKey;
        Texture2D _texture; 
    };

}