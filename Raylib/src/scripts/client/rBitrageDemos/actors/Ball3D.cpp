#include "client/rBitrageDemos/actors/Ball3D.h"
#include "Ball3D.h"

namespace RMC::rBitrage 
{
    Ball3D::Ball3D(Game& game) 
        : Shape3D(game, new SphereShapeData3D),
            _mixin(PositionVelocityBoundsMixin(*this, GetVelocity()))
    { 
        _velocity = {0, 0, 0};

        //TODO: I'd like "Actor.cpp" to set once to the value that is 'whatever is the child class'
        SetName("Ball3D");
    }

    Ball3D::~Ball3D()
    {
    }

    void Ball3D::OnFrameUpdate(float deltaTime)
    {
        Shape3D::OnFrameUpdate(deltaTime);

        _transform.Position.x += _velocity.x * deltaTime;
        _transform.Position.y += _velocity.y * deltaTime;
        _transform.Position.z += _velocity.z * deltaTime;

        Vector3 velocityBefore = GetVelocity();
 
        //Mixin will update the velocity, if needed to bounce off edge
        _mixin.OnFrameUpdate(deltaTime);

        //Did it bounce? Play sound
        if (!Vector3Equals(GetVelocity(), velocityBefore))
        {

            if (_game.HasSystem<AudioSystem>())
            {
                _game.GetSystem<AudioSystem>()->PlaySound("Hit01");
            }
        }
    }

    Vector3& Ball3D::GetVelocity() 
    {
        return _velocity;
    }

    void Ball3D::SetVelocity(const Vector3& velocity) 
    {
        _velocity = velocity;
    }
}