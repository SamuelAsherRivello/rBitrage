#include "client/rBitrageDemos/actors/Ball2D.h"

namespace RMC::rBitrage 
{
        
    Ball2D::Ball2D(Game& game, const char *assetKey) 
        : Sprite2D(game, assetKey), 
            _mixin(PositionVelocityBoundsMixin(*this, GetVelocity()))
    {
    }

    Ball2D::~Ball2D()
    {
    }

    void Ball2D::OnFrameUpdate(float deltaTime)
    {
        Sprite2D::OnFrameUpdate(deltaTime);

        //MOVE
        _transform.Position.x += (GetVelocity().x * deltaTime);
        _transform.Position.y += (GetVelocity().y * deltaTime);
        _transform.Position.z += (GetVelocity().z * deltaTime);

        //TEMP
        _transform.Rotation.z += (GetVelocity().x  * deltaTime) / 2;

        Vector3 velocityBefore = GetVelocity();
 
        //Mixin will update the velocity, if needed to bounce off edge
        _mixin.OnFrameUpdate(deltaTime);

        //Did it bounce? Play sound
        if (!Vector3Equals(GetVelocity(), velocityBefore))
        {

            OnBounce.Invoke(); 

            if (_game.HasSystem<AudioSystem>())
            {
                _game.GetSystem<AudioSystem>()->PlaySound("Hit01");
            }
        }

        
    }

}