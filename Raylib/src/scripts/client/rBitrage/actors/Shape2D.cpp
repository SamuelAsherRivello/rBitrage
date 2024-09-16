#include "client/rBitrage/actors/Shape2D.h"
#include "Shape2D.h"

namespace RMC::rBitrage
{
    Shape2D::Shape2D(Game& game, const FrameRenderLayer& frameRenderLayer)
        : Actor2D(game, "", frameRenderLayer), _shapeData2D() {}

    Shape2D::Shape2D(Game& game, ShapeData2D* shapeData2D, const FrameRenderLayer& frameRenderLayer)
        : Shape2D(game, frameRenderLayer)  
    {
        _shapeData2D = shapeData2D;

        //TODO: Why is this 2 lines? Because of const or &? 
        auto size = Utilities::ToVector3(_shapeData2D->GetSize());
        GetBoundsLocal().SetSize(size);

    }

    Shape2D::~Shape2D() 
    {
        delete _shapeData2D;
    }

    void Shape2D::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
        Actor2D::OnFrameRender(frameRenderLayer);

        _shapeData2D->Draw
        (
            Utilities::ToVector2(GetBoundsGlobal().GetCenter()), 
            Utilities::ToVector2(GetBoundsGlobal().GetSize())
        );
    }
}
