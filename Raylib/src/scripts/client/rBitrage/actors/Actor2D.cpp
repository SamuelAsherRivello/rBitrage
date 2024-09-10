#include "client/rBitrage/actors/Actor2D.h"

namespace RMC::rBitrage 
{

    Actor2D::Actor2D(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, assetKey, frameRenderLayer)
    {

    }


    Actor2D::~Actor2D() 
    {
    }

    /*
    * Resize the Actor ASSET to this size
    */
    void Actor2D::ResizeAsset(const Vector3& size) 
    {
        //override as needed
    }

    /*
    * Resize the Actor ASSET to the ASSET original size
    */
    void Actor2D::ResizeAsset() 
    {
        //override as needed
    }


}