
#pragma once
#include <raylib.h>


namespace RMC::rBitrage 
{

    Color RBITRAGE_SHAPE2D_DEFAULT_COLOR = BLUE;
    Color RBITRAGE_BACKGROUND2D_DEFAULT_COLOR = LIGHTGRAY;

    class ShapeData2D
    {
        public:
            ShapeData2D() : _color (RBITRAGE_SHAPE2D_DEFAULT_COLOR)
            {
            }
            ShapeData2D(Color color) 
            {
                _color = color;
            }
            virtual void Draw (Vector2 position, Vector2 size) const
            {
                //TODO: Remove this DRAW after debugging inhertience
                DrawCircleV(position, size.x, _color);
            }
        protected:
            Color _color;
    };

    class CircleShapeData2D : public ShapeData2D
    {
        public:
            CircleShapeData2D(Color color = RBITRAGE_SHAPE2D_DEFAULT_COLOR) : ShapeData2D(color) {}
            void Draw (Vector2 position, Vector2 size) const override
            {
                //Raylib draws circles CENTERED on the position. GOOD!
                //I choose to average x/y into radius. Users must pass x==y for predictable results
                DrawCircleV(position, Utilities::ToVector2Average({size.x, size.y}).x, _color);

            }
    };

    class RectangleShapeData2D : public ShapeData2D
    {
        public:
            RectangleShapeData2D(Color color = RBITRAGE_SHAPE2D_DEFAULT_COLOR) : ShapeData2D(color) {}
            void Draw (Vector2 position, Vector2 size) const override
            {
                //Raylib draws rectangles NOT-CENTERED on the position. BAD! Adjusted here.
                DrawRectangleV({position.x - size.x/2, position.y - size.y/2}, size, _color);
            }
    };

}