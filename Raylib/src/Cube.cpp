#include "Cube.h"
#include "Actor.h"
#include <raylib.h>
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include <iostream>

Cube::Cube(Game& game) : Actor(game, "src/assets/images/itch.io/projectTemplate/Paddle01.png") { 
    _speed = 1000;
    _isCollision = false;
}

Cube::~Cube()
{
}

void Cube::OnFixedUpdate(float fixedDeltaTime)
{
    Actor::OnFixedUpdate(fixedDeltaTime);

    if (_game.HasSystem<RMC::rBitrage::PhysicsSystem>())
    {
        _isCollision = _game.GetSystem<RMC::rBitrage::PhysicsSystem>()->IsCollision(this);
        //std::cout << "_isCollision" << _isCollision << std::endl;
    }

}

void Cube::OnFrameUpdate(float deltaTime)
{
    Actor::OnFrameUpdate(deltaTime);

    // Input
    if (_game.HasSystem<RMC::rBitrage::InputSystem>()) {

        Vector3 deltaPosition = Vector3();

        if (_game.GetSystem<RMC::rBitrage::InputSystem>()->IsActionDown("up"))
        {
            //std::cout << "Up" << std::endl; 
            deltaPosition.y -= _speed;
        }
        if (_game.GetSystem<RMC::rBitrage::InputSystem>()->IsActionDown("down"))
        {
            //std::cout << "Down" << std::endl;
            deltaPosition.y += _speed;
        }
        if (_game.GetSystem<RMC::rBitrage::InputSystem>()->IsActionDown("left"))
        {
            //std::cout << "Left" << std::endl;
            deltaPosition.x -= _speed;
        }
        if (_game.GetSystem<RMC::rBitrage::InputSystem>()->IsActionDown("right"))
        {
            //std::cout << "Right" << std::endl;
            deltaPosition.x += _speed;
        }
        if (_game.GetSystem<RMC::rBitrage::InputSystem>()->IsActionPressed("action"))
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
    }


}

void Cube::OnFrameRender(const FrameRenderLayer& frameRenderLayer)
{
    Actor::OnFrameRender(frameRenderLayer);

    if (_frameRenderLayer != frameRenderLayer)
    {
        return;
    }

    if (_isCollision)
    {
        DrawRectangleLinesEx(GetBounds(), 8, BLUE);
    }
   
}
