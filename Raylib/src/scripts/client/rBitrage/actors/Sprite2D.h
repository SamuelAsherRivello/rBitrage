
#pragma once
#include <raylib.h>

#include "client/rBitrage/actors/Actor2D.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Transform.h"
#include "client/rBitrage/systems/AssetLoaderSystem.h"

#include <iostream>
#include <string.h>

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Sprite2D : public Actor2D
    {
    public:
        Sprite2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
        virtual ~Sprite2D();

        void OnFrameRender() override;
        void SetSize(const Vector3 &size) override;

    protected:
        Texture2D _texture; 
    };

}