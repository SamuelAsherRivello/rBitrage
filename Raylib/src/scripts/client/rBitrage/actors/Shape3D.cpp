#include "client/rBitrage/actors/Shape3D.h"

namespace RMC::rBitrage
{
    Shape3D::Shape3D(Game& game, const FrameRenderLayer& frameRenderLayer)
        : Actor3D(game, "", frameRenderLayer), _shapeData3D() 
        {
            std::cout << "Color 1 " << std::endl;
        }

    Shape3D::Shape3D(Game& game, ShapeData3D* shapeData3D, const FrameRenderLayer& frameRenderLayer)
        : Shape3D(game, frameRenderLayer)  
    {
        std::cout << "Color 2 " << shapeData3D->_color.a << std::endl;
        _shapeData3D = new CubeShapeData3D(RED);
    }

    Shape3D::~Shape3D() 
    {
        delete _shapeData3D;
    }

    void Shape3D::OnFrameRender()
    {
        Actor3D::OnFrameRender();

        _shapeData3D = new CubeShapeData3D(RED);
        _shapeData3D->Draw(GetPosition(), GetBoundsLocal().GetSize());
        
    }
}
