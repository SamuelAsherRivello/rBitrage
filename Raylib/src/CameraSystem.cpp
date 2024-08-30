#include "Game.h"
#include "CameraSystem.h"
#include <iostream>

namespace RMC::ProjectTemplate 
{
    /**
     * DebugSystem renders the camera
     **/
    CameraSystem::CameraSystem(Game& game) : System(game) 
    {
    }

    void CameraSystem::OnInitialize() 
    {
        camera2D = Camera2D();
        //camera.target = (Vector2){ player.x + 20.0f, player.y + 20.0f };
        camera2D.offset = {_game.size.x/2, _game.size.y/2};
        camera2D.rotation = 0.0f;
        camera2D.zoom = 1;
    }

    void CameraSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        // std::cout << "OnFixedUpdate(" << fixedDeltaTime << ")" << std::endl;
    }

    void CameraSystem::OnFrameUpdate(float deltaTime) 
    {
        // std::cout << "OnFrameUpdate(" << deltaTime << ")" << std::endl;
        if (_targetActor.has_value())
        {
           
            camera2D.target = {(*_targetActor.value()).GetPosition().x, (*_targetActor.value()).GetPosition().y};
            //std::cout << "OnFixedUpdate(" << camera2D.target.x << ")" << std::endl;
        }

        
    }

    void CameraSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
  
    }

    
    Actor* CameraSystem::GetTargetActor()
    {
        return _targetActor.value();
    }

    void CameraSystem::SetTargetActor(Actor* targetActor) 
    {
        _targetActor.emplace(targetActor);
    }


} 
