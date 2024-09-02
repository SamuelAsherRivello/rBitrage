
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
            
            Rectangle ToRectangle()
            {
                return 
                    {
                        center.x - (size.x / 2),
                        center.y - (size.y / 2),
                        size.x,
                        size.y
                    };
            }

            Vector3 center;
            Vector3 size;
        private:

    };
}