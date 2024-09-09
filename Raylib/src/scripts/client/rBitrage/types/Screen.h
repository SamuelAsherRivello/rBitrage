// src/Action.h

#pragma once
#include "client/rBitrage/types/Bounds.h"

namespace RMC::rBitrage 
{
    class Screen : public Bounds 
    {
        public:
            /**
             * The Screen of 2D or 3D actors
             */
            Screen(float width, float height) : Bounds
                ( 
                    //TODO: Is -1 a good 'ignore me' value?
                    { width, height, -1 },

                    //DEFAULT: For sccreen will be upper left. Done!
                    { 0.0f, 0.0f, 0.0f }
                )
            {
            }
            bool isDebug = false;

        private:

    };
}