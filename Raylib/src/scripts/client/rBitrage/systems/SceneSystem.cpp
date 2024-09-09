
#include "client/rBitrage/systems/SceneSystem.h"


namespace RMC::rBitrage 
{
    /**
     * System for showing all contents in the world AT A GIVEN MOMENT
     */
    SceneSystem::SceneSystem(Game& game) : System(game) 
    {

    }

    void SceneSystem::OnInitialize() 
    {
        currentScene = new Scene();
    }


    void SceneSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
    }


    void SceneSystem::OnFrameUpdate(float deltaTime) 
    {
    }


    void SceneSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
        
    }

} 
