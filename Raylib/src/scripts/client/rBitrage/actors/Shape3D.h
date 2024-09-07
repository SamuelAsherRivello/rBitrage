#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Actor3D.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/utilities/Utilities.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Transform.h"
#include "client/rBitrage/types/Shape.h"

namespace RMC::rBitrage
{
    class Shape3D : public Actor3D
    {
        public:
            //TODO: use data3d
            Shape3D(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
            Shape3D(Game& game, ShapeData2D& shapeData2D, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);

            virtual ~Shape3D();
            

            void OnFrameRender() override;

        protected:
            ShapeData2D _shapeData2D;
    };
}
