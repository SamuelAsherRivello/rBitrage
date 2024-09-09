// src/Action.h

#pragma once
#include <raylib.h>
#include "client/rBitrage/types/Bounds.h"

namespace RMC::rBitrage 
{
    //Extend Bounds
    class World : public Bounds 
    {
        public:
            /**
             * The world of 2D or 3D actors
             */
            World(float width, float height, float depth) : Bounds( 

                //TODO: Finite is good default (in 2d g), but maybe make infinite an option
                { width, height, depth },

                //DEFAULT: The world center is at the midway of the size
                { width/2, height/2, depth/2  })

            {
            }

            bool isDebug = false;

        private:

    };
}