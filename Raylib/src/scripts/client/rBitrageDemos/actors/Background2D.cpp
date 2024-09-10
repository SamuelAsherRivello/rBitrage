#include "client/rBitrageDemos/actors/Background2D.h"


namespace RMC::rBitrage 
{
    Background2D::Background2D(Game& game, Color color) 
        : Shape2D(game, FrameRenderLayer::PreCamera)
    {
        _shapeData2D = new RectangleShapeData2D(color);

        //Background automatically always covers the screen
        ResizeAsset(_game.world.GetSize());
        SetPosition(game.world.GetCenter());
    }

    Background2D::~Background2D() {}

}