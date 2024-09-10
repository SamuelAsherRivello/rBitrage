
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

        PositionVelocityBoundsMixin(Actor& actor, Vector3* velocityPtr) 
            : Mixin(actor), _velocityPtr(velocityPtr)
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

            const float minX = _actor.GetGame().world.GetMin().x;
            const float maxX = _actor.GetGame().world.GetMax().x;
            const float minY = _actor.GetGame().world.GetMin().y;
            const float maxY = _actor.GetGame().world.GetMax().y;

       

            Vector3 velocityCopy = *_velocityPtr;
            bool hasChangedDirection = false;
            if (velocityCopy.x < 0 && _actor.GetTransform().Position.x - _actor.GetBounds().GetSize().x/2 <= minX)
            {
                velocityCopy.x *= -1;
                hasChangedDirection = true;
            }
                
            else if (velocityCopy.x > 0 && _actor.GetTransform().Position.x + _actor.GetBounds().GetSize().x/2 >= maxX)
            {
                velocityCopy.x *= -1;
                hasChangedDirection = true;
            }
            
            if (velocityCopy.y < 0 && _actor.GetTransform().Position.y - _actor.GetBounds().GetSize().y/2 <= minY)
            {
                velocityCopy.y *= -1;
                hasChangedDirection = true;
            }
                
            else if (velocityCopy.y > 0 && _actor.GetTransform().Position.y + _actor.GetBounds().GetSize().y/2 >= maxY)
            {
                velocityCopy.y *= -1;
                hasChangedDirection = true;
            }

            if (velocityCopy.z < 0 && _actor.GetTransform().Position.z - _actor.GetBounds().GetSize().z/2 <= minY)
            {
                velocityCopy.z *= -1;
                hasChangedDirection = true;
            }
                
            else if (velocityCopy.z > 0 && _actor.GetTransform().Position.z + _actor.GetBounds().GetSize().z/2 >= maxY)
            {
                velocityCopy.z *= -1;
                hasChangedDirection = true;
            }

            std::cout << Utilities::ToString(_actor.GetInstanceId()) << " and " << Utilities::ToString(*_velocityPtr) << " and " << hasChangedDirection << std::endl;


            if (hasChangedDirection) {
                *_velocityPtr = velocityCopy;
            }
        }


        void OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
        {

        }

    private:
        Vector3* _velocityPtr;
    };
}