
#pragma once
#include <raylib.h>

namespace RMC::rBitrage 
{
    class Bounds
    {
        public:
            Bounds(Vector3 center, Vector3 size)
            {
                _center = center;
                _size = size;
            }

            Rectangle ToRectangle()
            {
                return 
                    {
                        _center.x - (_size.x / 2),
                        _center.y - (_size.y / 2),
                        _size.x,
                        _size.y
                    };
            }
        private:
            Vector3 _center;
            Vector3 _size;
    };
}