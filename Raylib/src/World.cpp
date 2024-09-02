#include "World.h"
#include "Bounds.h"

namespace RMC::rBitrage 
{
    /**
     * The world of 2D or 3D actors
     */
    World::World() : Bounds( 

        //Origin
        { 0.0f, 0.0f, 0.0f },

        //TODO: pass infinite size?
        { 1000, 1000, 1000 })
    {
    }
    
}