#include "client/rBitrage/actors/Shape3D.h"

namespace RMC::rBitrage
{
    Shape3D::Shape3D(Game& game, const FrameRenderLayer& frameRenderLayer)
        : Actor3D(game, "", frameRenderLayer), _shapeData2D() {}

    Shape3D::Shape3D(Game& game, ShapeData2D& shapeData2D, const FrameRenderLayer& frameRenderLayer)
        : Shape3D(game, frameRenderLayer)  
    {
        _shapeData2D = shapeData2D;
    }

    Shape3D::~Shape3D() {}

    void Shape3D::OnFrameRender()
    {
        Actor3D::OnFrameRender();

        //TODO: use shapedata3d and move this in there
        //Do that AFTER solving 2d shapes
        //_shapeData2D.Draw(Utilities::ToVector2(GetPosition()), Utilities::ToVector2(GetSize()));

        //Temp 3d drawing
        DrawSphereEx(_transformation.Position, _size.x, 10, 20, WHITE);
    }
}
