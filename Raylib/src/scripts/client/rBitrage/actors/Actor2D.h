
#pragma once
#include <raylib.h>
#include <iostream>
#include <string.h>
#include "client/rBitrage/actors/Actor.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"

namespace RMC::rBitrage 
{
    class Actor2D : public Actor
    {
        public:
            Actor2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
            virtual ~Actor2D();

        protected:
    };

}