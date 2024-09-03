
#pragma once
#include <raylib.h>

namespace RMC::rBitrage 
{
    class Bounds
    {
        public:
        
            Bounds(Vector3 center, Vector3 size)
            {
                this->center = center;
                this->size = size;
            }

            Vector3 GetMin()
            {
                return {center.x - (size.x / 2), center.y - (size.y / 2), center.z - (size.z / 2)};
            }

            Vector3 GetMax()
            {
                return {center.x + (size.x / 2), center.y + (size.y / 2), center.z + (size.z /2 )};
            }
            
            Rectangle ToRectangle(Vector3 pivot = {0.5f, 0.5f, 0.5f}) // updated method with pivot parameter
            {
                float x = center.x - size.x / 2 + (pivot.x * size.x);
                float y = center.y - size.y / 2 + (pivot.y * size.y);

                return {x, y, size.x, size.y};
            }

            Vector3 center;
            Vector3 size;
        private:

    };
}