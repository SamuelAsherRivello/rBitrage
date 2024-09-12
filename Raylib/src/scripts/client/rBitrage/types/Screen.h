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
                    //Size
                    { width, height, -1 },

                     //TODO: Is -1 a good 'ignore me' value?
                     //Center
                    { width/2, height/2, -1/2 },

                    //TODO: Is -1 a good 'ignore me' value?
                    //Pivot
                    { width/2, height/2, -1/2 }
                    )
            {
            }

            bool isDebug = false;

            //Subclass allows more public access than parent
            void SetSize(Vector3 size) 
            { 
                Bounds::SetSize(size);
            }

        private:

    };
}