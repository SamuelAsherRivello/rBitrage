
#pragma once
#include <raylib.h>
#include <iostream>
#include <string.h>
#include "client/rBitrage/actors/Actor.h"
#include "client/rBitrage/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"

namespace RMC::rBitrage 
{
    class Actor3D : public Actor
    {
        public:
            Actor3D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);
            virtual ~Actor3D();

        protected:
    };

}