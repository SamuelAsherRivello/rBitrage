#include "OrbitPlayer.h"
#include "Actor2D.h"
#include <raylib.h>
#include <raymath.h>
#include "InputSystem.h"
#include "AudioSystem.h"
#include <iostream>

namespace RMC::rBitrage 
{
    OrbitPlayer::OrbitPlayer(Game& game) :  Actor2D(game, "OrbitPlayer")  {

        SetIsDebug(true);
        _orbitCenter = {0,0,0};
        _orbitRadius = 300;
        _velocityAngular = 0;
        _accelerationAngularInput = 0.95f;
        _accelerationAngularFriction = (0.95f);
    }

    OrbitPlayer::~OrbitPlayer()
    {
    }

    void OrbitPlayer::OnFixedUpdate(float fixedDeltaTime)
    {
        Actor2D::OnFixedUpdate(fixedDeltaTime);
    }

    void OrbitPlayer::OnFrameUpdate(float deltaTime)
    {
        Actor2D::OnFrameUpdate(deltaTime);
        if (_game.HasSystem<InputSystem>())
        {
            _accelerationAngularInput += (_game.GetSystem<InputSystem>()->IsActionDown("left") ? 100 : 0) * deltaTime;
            _accelerationAngularInput += (_game.GetSystem<InputSystem>()->IsActionDown("right") ? -100 : 0) * deltaTime;

            if (_game.GetSystem<InputSystem>()->IsActionDown("action"))
            {

                _game.GetSystem<AudioSystem>()->PlaySound("Hit03");

                // auto bullet = std::make_unique<Actor2D>(_game, "Bullet", FrameRenderLayer::PreCamera);
                // bullet->SetSize({_game.screen.size.x/100, _game.screen.size.y/100, 0});
                // bullet->SetPosition(GetPosition());

                // // Transfer ownership to the game object
                // _game.AddActor(std::move(bullet)); // Move the unique_ptr to the _game object
            }
        }

        // Limit the angular velocity to a max value
        if (_accelerationAngularInput > _accelerationAngularInputMax)
        {
            _accelerationAngularInput = _accelerationAngularInputMax;
        }
        else if (_accelerationAngularInput < -_accelerationAngularInputMax)
        {
            _accelerationAngularInput = -_accelerationAngularInputMax;
        }

        // Apply friction to reduce angular velocity
        _accelerationAngularInput *= (1 - _accelerationAngularFriction * deltaTime);

        // Update player position using trigonometry
        _velocityAngular += _accelerationAngularInput * deltaTime;

        _transformation.Position.x = _orbitCenter.x + sin(_velocityAngular) * _orbitRadius;
        _transformation.Position.y = _orbitCenter.y + cos(_velocityAngular) * _orbitRadius;

        // Calculate the angle in radians
        float deltaX = _orbitCenter.x - _transformation.Position.x;
        float deltaY = _orbitCenter.y - _transformation.Position.y;
        float angleToCenter = atan2(deltaY, deltaX) * (180.0 / PI) + 90;
        _transformation.Rotation.z = angleToCenter;

    }

    void OrbitPlayer::OnFrameRender()
    {
        Actor2D::OnFrameRender();
    }


    void OrbitPlayer::SetOrbitCenter(const Vector3& orbitCenter) 
    {
        _orbitCenter = orbitCenter;
    }
    Vector3 OrbitPlayer::GetOrbitCenter() const
    {
        return _orbitCenter;
    }

}