#include "client/rBitrage/actors/Cube2D.h"

namespace RMC::rBitrage 
{
    Cube2D::Cube2D(Game& game) : Sprite2D(game, "Paddle01") { 
        _velocityLinear = {1000,1000,0};
        _velocityAngular = {0, 0, 100};
        _isCollision = false;
    }

    Cube2D::~Cube2D()
    {
    }

    void Cube2D::OnFixedUpdate(float fixedDeltaTime)
    {
        Sprite2D::OnFixedUpdate(fixedDeltaTime);

        if (_game.HasSystem<PhysicsSystem>())
        {
            _isCollision = _game.GetSystem<PhysicsSystem>()->IsCollision(this);
            //std::cout << "_isCollision" << _isCollision << std::endl;
        }

    }

    void Cube2D::OnFrameUpdate(float deltaTime)
    {
        Sprite2D::OnFrameUpdate(deltaTime);

        // Input
        if (_game.HasSystem<InputSystem>()) {

            Vector3 deltaPosition = Vector3();
            Vector3 deltaRotation = Vector3();

            if (_game.GetSystem<InputSystem>()->IsActionDown("up"))
            {
                //std::cout << "Up" << std::endl; 
                deltaPosition.y -= _velocityLinear.y;
            }
            if (_game.GetSystem<InputSystem>()->IsActionDown("down"))
            {
                //std::cout << "Down" << std::endl;
                deltaPosition.y += _velocityLinear.y;
            }
            if (_game.GetSystem<InputSystem>()->IsActionDown("left"))
            {
                //std::cout << "Left" << std::endl;
                deltaPosition.x -= _velocityLinear.x;
                deltaRotation.z -= _velocityAngular.z;
            }
            if (_game.GetSystem<InputSystem>()->IsActionDown("right"))
            {
                //std::cout << "Right" << std::endl;
                deltaPosition.x += _velocityLinear.x;
                deltaRotation.z += _velocityAngular.z;
            }
            if (_game.GetSystem<InputSystem>()->IsActionPressed("action"))
            {
                std::cout << "Action" << std::endl;
            }

            //TODO: Possible future features...
            //         1. SetPositionBy(delta)
            //         2. have a concept of velocity and friction (sounds like physics, but it could be useful for a "non physics" game too?)
            Vector3 position = GetPosition();
            Vector3 newPosition = Vector3({
                position.x + deltaPosition.x * deltaTime, 
                position.y + deltaPosition.y * deltaTime , 
                position.z + deltaPosition.z * deltaTime});
            SetPosition(newPosition);

            Vector3 rotation = GetRotation();
            Vector3 newRotation = Vector3({
                rotation.x + deltaRotation.x * deltaTime, 
                rotation.y + deltaRotation.y * deltaTime , 
                rotation.z + deltaRotation.z * deltaTime});
            SetRotation(newRotation);
        }


    }

    void Cube2D::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
    {
        Sprite2D::OnFrameRender(frameRenderLayer);

        //TODO: If/when collision is added to actor, then move this drawing to debugsystem
        if (_isCollision)
        {
            //DrawRectangleLinesEx(GetBounds().ToRectangle(), 8, BLUE);
        }
    
    }
}