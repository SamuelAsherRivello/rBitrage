#include "client/rBitrage/systems/CameraSystem.h"

namespace RMC::rBitrage 
{

    /**
     * DebugSystem renders the camera
     **/
    CameraSystem::CameraSystem(Game& game, CameraSystemMode cameraSystemMode) : System(game) 
    {
        this->cameraSystemMode = cameraSystemMode;
    }

    void CameraSystem::OnInitialize() 
    {
        camera2D = Camera2D();

        //TODO: should these use "world" not screen?
        if (cameraSystemMode != CameraSystemMode::Cam3D)
        {
            //By default look at the center of the world
            camera2D.target = Utilities::ToVector2(_game.world.GetCenter());

            //TODO: Should offset be based on SCREEN not WORLD?
            camera2D.offset = {_game.world.GetSize().x / 2,_game.world.GetSize().y / 2};
            camera2D.rotation = 0.0f;
            camera2D.zoom = 1;
        }
   
        if (cameraSystemMode != CameraSystemMode::Cam2D)
        {
            //TODO: What is a good default position for the camera? 
            //IDEA: Center
            Vector3 cameraPosition = _game.world.GetCenter();
            //IDEA: Plus world size
            cameraPosition = Vector3Add(cameraPosition, { _game.world.GetSize().x,_game.world.GetSize().y, _game.world.GetSize().z});
            //IDEA: Plus some magic offset
            cameraPosition = Vector3Add(cameraPosition, {-1200, -1200, -1200}); //TODO: Reduce/remove this

            camera3D = Camera3D();
            camera3D.position = cameraPosition;
            camera3D.target = _game.world.GetCenter();
            camera3D.up = (Vector3){ 0.0f, 1.0f, 0.0f };
            camera3D.fovy = 60.0;
            camera3D.projection = CAMERA_PERSPECTIVE;
        }
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
