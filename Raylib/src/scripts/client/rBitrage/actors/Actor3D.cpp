#include "client/rBitrage/actors/Actor3D.h"

namespace RMC::rBitrage 
{

    Actor3D::Actor3D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, assetKey, frameRenderLayer)
    {
        //GOOD DEFAULT FOR 3d like units. But think differently for 2d default
        //TODO: Think about adding 'Scale', separate from 'Size' like unity?
        //Measurement is like UNITS
        SetSize({1, 1, 1});
    }


    Actor3D::~Actor3D() 
    {
    }

}