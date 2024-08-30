
#pragma once
#include <raylib.h>

namespace RMC::rBitrage 
{
    //TODO: this has the same name as a class in raylib. Problem?
    class Transform
    {
        public:
            //This is euler
            Vector3 Rotation = {0, 0, 0};
            Vector3 Position = {0, 0, 0}; 
    };
}
