
#pragma once
#include <raylib.h>
#include "client/rBitrage/utilities/Utilities.h"


namespace RMC::rBitrage 
{
    class ModelData3D
    {
        public:
            ModelData3D() 
            {
            }

            ModelData3D(const char* modelAssetKey, const char* textureAssetKey, Vector3 scale = {1, 1, 1}, Color color = WHITE) : 
                modelAssetKey(modelAssetKey), textureAssetKey(textureAssetKey), scaleFactor(scale), color(color)
            {
            }
            const char* modelAssetKey;
            const char* textureAssetKey;
            Vector3 scaleFactor;
            Color color;
        protected:
          
    };


}