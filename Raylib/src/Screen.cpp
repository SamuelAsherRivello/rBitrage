#include "Screen.h"
#include "Bounds.h"

namespace RMC::rBitrage 
{
    /**
     * The Screen of 2D or 3D actors
     */
    Screen::Screen(float width, float height) : Bounds
        ( 
            //Origin
            { 0.0f, 0.0f, 0.0f },

            //TODO: pass "ignore me" value for z like -1?
            { width, height, 1000 }
        )
    {
    }
}