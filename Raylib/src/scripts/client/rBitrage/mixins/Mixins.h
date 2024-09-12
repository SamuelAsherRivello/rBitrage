
#pragma once
#include <raylib.h>
#include "client/rBitrage/actors/Actor.h"


namespace RMC::rBitrage 
{
    class Mixin
    {
    public:

        Mixin(Actor& actor) : _actor(actor)
        {
        }

        ~Mixin() 
        {
            std::cout << "Mixin destroy " << std::endl;
        }


        void OnInitialize() 
        {

        }

        
        void OnInitialized() 
        {

        }


        void OnFixedUpdate(float fixedDeltaTime) 
        {

        }


        void OnFrameUpdate(float deltaTime) 
        {

        }


        void OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
        {

        }

    protected:
        Actor& _actor;

    private:
      
    };

    class PositionVelocityBoundsMixin : public Mixin
    {
    public:

        PositionVelocityBoundsMixin(Actor& actor, Vector3& velocityRef) 
            : Mixin(actor), _velocityRef(velocityRef)
        {
        }

        void OnInitialize() 
        {

        }

        
        void OnInitialized() 
        {

        }


        void OnFixedUpdate(float fixedDeltaTime) 
        {

        }


        void OnFrameUpdate(float deltaTime) 
        {

            //TODO: move this to the mixin.h
            const float worldMinX = _actor.GetGame().world.GetMin().x;
            const float worldMinY = _actor.GetGame().world.GetMin().y;
            const float worldMinZ = _actor.GetGame().world.GetMin().z;
            //
            const float worldMaxX = _actor.GetGame().world.GetMax().x;
            const float worldMaxY = _actor.GetGame().world.GetMax().y;
            const float worldMaxZ = _actor.GetGame().world.GetMax().z;

            //
            Bounds actorBoundsGlobal = _actor.GetBoundsGlobal();
            const float actorMinX = actorBoundsGlobal.GetMin().x;
            const float actorMinY = actorBoundsGlobal.GetMin().y;
            const float actorMinZ = actorBoundsGlobal.GetMin().z;
            //
            const float actorMaxX = actorBoundsGlobal.GetMax().x;
            const float actorMaxY = actorBoundsGlobal.GetMax().y;
            const float actorMaxZ = actorBoundsGlobal.GetMax().z;

            Vector3 nextVelocity = _velocityRef;

            bool hasChangedDirection = false;
            if (actorMinX < worldMinX)
            {
                nextVelocity.x *= -1;
                hasChangedDirection = true;
            }
                
            else if (actorMaxX >= worldMaxX)
            {
        
                nextVelocity.x *= -1;
                hasChangedDirection = true;
            }
            
            if (actorMinY < worldMinY)
            {
                nextVelocity.y *= -1;
                hasChangedDirection = true;
            }
            else if (actorMaxY >= worldMaxY)
            {
                nextVelocity.y *= -1;
                hasChangedDirection = true;
            }

            //TODO: Enable this for 3d, maybe harmlessly keep it for 2D too, if it works
            // if (actorMinZ < worldMinZ)
            // {
            //     nextVelocity.z *= -1;
            //     hasChangedDirection = true;
            // }
            // else if (actorMaxZ >= worldMaxZ)
            // {
            //     nextVelocity.z *= -1;
            //     hasChangedDirection = true;
            // }

            if (hasChangedDirection) {
                _velocityRef = nextVelocity;
            }
        }


        void OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
        {

        }

    private:
        Vector3& _velocityRef;
    };
}