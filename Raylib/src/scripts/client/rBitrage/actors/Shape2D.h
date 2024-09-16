#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Actor2D.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Transform.h"
#include "client/rBitrage/types/ShapeDatas.h"

namespace RMC::rBitrage
{
    class Shape2D : public Actor2D
    {
        public:
            Shape2D(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
            Shape2D(Game& game, ShapeData2D* shapeData2D, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);

            virtual ~Shape2D();

            void OnFrameRender(const FrameRenderLayer &frameRenderLayer) override;
            
        protected:
            ShapeData2D* _shapeData2D;
    };
}
