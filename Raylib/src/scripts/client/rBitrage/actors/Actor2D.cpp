#include "client/rBitrage/actors/Actor2D.h"

namespace RMC::rBitrage 
{

    Actor2D::Actor2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, assetKey, frameRenderLayer)
    {

         //GOOD DEFAULT FOR 2d like pixels. But think differently for 3d default
        //TODO: Think about adding 'Scale', separate from 'Size' like unity?
        //Measurement is like PIXELS
        SetSize({32, 32, 32});
    }


    Actor2D::~Actor2D() 
    {
    }

}