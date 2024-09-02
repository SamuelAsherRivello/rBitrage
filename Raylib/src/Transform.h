
#pragma once
#include <raylib.h>

namespace RMC::rBitrage 
{
    class Transform
    {
        public:
            //This is euler
            Vector3 Rotation = {0, 0, 0};
            Vector3 Position = {0, 0, 0}; 
    };
}
