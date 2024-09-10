#include "client/rBitrage/actors/Shape2D.h"

namespace RMC::rBitrage
{
    Shape2D::Shape2D(Game& game, const FrameRenderLayer& frameRenderLayer)
        : Actor2D(game, "", frameRenderLayer), _shapeData2D() {}

    Shape2D::Shape2D(Game& game, ShapeData2D* shapeData2D, const FrameRenderLayer& frameRenderLayer)
        : Shape2D(game, frameRenderLayer)  
    {
        _shapeData2D = shapeData2D;
    }

    Shape2D::~Shape2D() 
    {
        delete _shapeData2D;
    }

    void Shape2D::OnFrameRender()
    {
        Actor2D::OnFrameRender();

        _shapeData2D->Draw(Utilities::ToVector2(GetPosition()), Utilities::ToVector2(GetBounds().GetSize()));
    }
}
