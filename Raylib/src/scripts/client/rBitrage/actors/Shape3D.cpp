#include "client/rBitrage/actors/Shape3D.h"
#include "Shape3D.h"

namespace RMC::rBitrage
{
    //NOTE: We need 2 constructors here. One for the default constructor and one for the copy constructor.
    Shape3D::Shape3D(Game& game, const FrameRenderLayer& frameRenderLayer)
        : Actor3D(game, "", frameRenderLayer), _shapeData3D(new SphereShapeData3D()) 
    {
    }

    Shape3D::Shape3D(Game& game, ShapeData3D* shapeData3D, const FrameRenderLayer& frameRenderLayer)
        : Shape3D(game, frameRenderLayer)  
    {
        
        _shapeData3D = new SphereShapeData3D(RED);

         //TODO: Why is this 2 lines? Because of const or &? 
        Vector3 size = _shapeData3D->GetSize();

        SetScale({1, 1, 1});
        GetBoundsLocal().SetSize(size);
    }

    Shape3D::~Shape3D() 
    {
        delete _shapeData3D;
    }

    void Shape3D::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
        Actor3D::OnFrameRender(frameRenderLayer);

        _shapeData3D->Draw(GetPosition(), GetBoundsGlobal().GetSize());
        
    }
}
