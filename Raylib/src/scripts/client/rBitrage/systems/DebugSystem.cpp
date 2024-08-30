
#include "client/rBitrage/systems/DebugSystem.h"


namespace RMC::rBitrage 
{
    /**
     * System for showing developer-facing info
     * in the console and onscreen. 
     */
    DebugSystem::DebugSystem(Game& game) : System(game) 
    {

    }

    void DebugSystem::OnInitialize() 
    {

    }


    void DebugSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        // std::cout << "OnFixedUpdate(" << fixedDeltaTime << ")" << std::endl;
    }


    void DebugSystem::OnFrameUpdate(float deltaTime) 
    {
        // std::cout << "OnFrameUpdate(" << deltaTime << ")" << std::endl;
    }


    void DebugSystem::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
    {
        
        //FPS
        if (frameRenderLayer != FrameRenderLayer::PostCamera )
        {
            return;
        }

        DrawFPS(50, 120);   

  

        if (_game.GetSystem<CameraSystem>()->cameraSystemMode != CameraSystemMode::Cam2D)
        {
            //3d Grid
            if (_game.world.isDebug)
            {
                DrawGrid(10, 1.0f);
            }
        }
     
        if (_game.GetSystem<CameraSystem>()->cameraSystemMode != CameraSystemMode::Cam3D)
        {
            //1 of 2 Draw world first, thicker
            if (_game.world.isDebug)
            {
                DrawWorldSizeHalf();
                DrawWorldBounds();
            }
            
        }

        if (_game.screen.isDebug)
        {
            //2 of 2 Draw screen after, thinner
            DrawScreenSizeHalf();
            DrawScreenBounds();
        }

        //Draw box around actors for debugging
        for (Actor* actor : _game.GetActors()) {

            if (!actor->GetIsDebug())
            {
                continue;
            }
            //Ignore actor layer, draw it here
            DrawActorBounds(actor);
            DrawActorPivot(actor);
            DrawActorCenter(actor);
          
        }
    }

//1
    void DebugSystem::DrawWorldSizeHalf() 
    {
        Rectangle worldRect = {_game.world.center.x, _game.world.center.y, _game.world.size.x, _game.world.size.y};
        DrawCrosshairsAtCenterRectangle(worldRect, .5, _worldStroke, _worldColor);  

    }

    void DebugSystem::DrawScreenSizeHalf() 
    {
        Rectangle screenRect = {_game.screen.center.x, _game.screen.center.y, _game.screen.size.x, _game.screen.size.y};
        DrawCrosshairsAtCenterRectangle(screenRect, 1.0, _screenStroke, _screenColor); //GREEN

    }

    void DebugSystem::DrawCrosshairsAtCenterRectangle(Rectangle rectangle, float scale, float thick, Color color)
    {
        //HORIZONTAL - TODO: Draw from mid left to mid right
        DrawLineEx(
            {rectangle.x,                   rectangle.y + rectangle.height/2},
            {rectangle.x + rectangle.width, rectangle.y + rectangle.height/2}, 
            thick, 
            color);
        
        //VERTICAL - TODO: draw from mid top to mid bottom
        DrawLineEx(
            {rectangle.x + rectangle.width/2, rectangle.y},
            {rectangle.x + rectangle.width/2, rectangle.y + rectangle.height}, 
            thick, 
            color);
    }

    void DebugSystem::DrawScreenBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.screen.size.x, _game.screen.size.y}, _screenStroke, _screenColor);
    }

    void DebugSystem::DrawWorldBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.world.size.x, _game.world.size.y}, _worldStroke, _worldColor);
    }


    void DebugSystem::DrawActorBounds(Actor* actor) 
    {
        DrawCrosshairsAtCenterRectangle(actor->GetBounds().ToRectangle(), 1.0, 4, GREEN);
    }

    //2
    void DebugSystem::DrawActorPivot(Actor* actor)
    {
        // Calculate the offset from the actor's center to the pivot point
        float offsetX = actor->GetPivot().x * actor->GetBounds().size.x;
        float offsetY = actor->GetPivot().y * actor->GetBounds().size.y;

        DrawCircle(
            actor->GetBounds().center.x + offsetX, 
            actor->GetBounds().center.y + offsetY, 
            _pivotRadius, 
            PURPLE);
    }

    //1
    void DebugSystem::DrawActorCenter(Actor* actor) 
    {
        DrawRectangle(
            actor->GetBounds().center.x - _centerRadius/2, 
            actor->GetBounds().center.y - _centerRadius/2, 
            _centerRadius, 
            _centerRadius, 
            WHITE);
    }

} 
