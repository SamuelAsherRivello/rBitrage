#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Actor3D.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Transform.h"
#include "client/rBitrage/types/ShapeDatas.h"

namespace RMC::rBitrage
{
    class Shape3D : public Actor3D
    {
        public:
            Shape3D(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);
            Shape3D(Game& game, ShapeData3D* shapeData3D, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera3D);

            virtual ~Shape3D();

            void OnFrameRender(const FrameRenderLayer &frameRenderLayer) override;
            
        protected:
            ShapeData3D* _shapeData3D;
    };
}
