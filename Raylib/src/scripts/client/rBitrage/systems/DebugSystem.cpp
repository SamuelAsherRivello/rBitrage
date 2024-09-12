
#include "client/rBitrage/systems/DebugSystem.h"
#include "DebugSystem.h"


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

    void DebugSystem::OnInitialized() 
    {

        

    }


    void DebugSystem::OnFixedUpdate(float fixedDeltaTime) 
    {
        // std::cout << "OnFixedUpdate(" << fixedDeltaTime << ")" << std::endl;
    }


    void DebugSystem::OnFrameUpdate(float deltaTime) 
    {
        // std::cout << "OnFrameUpdate(" << deltaTime << ")" << std::endl;

        if (_game.HasSystem<InputSystem>())
        {
            if (_game.GetSystem<InputSystem>()->IsActionDown("debug"))
            {
                std::cout << "DebugSystem Mouse " << Utilities::ToString(GetMousePosition()) << std::endl;
            }
        }

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
            DrawActor(actor);

        }
    }

//1
    void DebugSystem::DrawWorldSizeHalf() 
    {
        Rectangle rect = _game.world.ToRectangle(); 
        
        //TODO: fix drawing of this since rect changed?
        RenderCrosshairsAtRectangleCenter(rect, _crosshairScale, _worldStroke, _worldColor, "World Center");  

    }

    void DebugSystem::DrawScreenSizeHalf() 
    {
        Rectangle rect = _game.screen.ToRectangle();

         //TODO: fix drawing of this since rect changed?
        RenderCrosshairsAtRectangleCenter(rect, .2, _crosshairScale, _screenColor, "Screen Center");  

    }

   

    void DebugSystem::DrawScreenBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.screen.GetSize().x, _game.screen.GetSize().y}, _screenStroke, _screenColor);
    }

    void DebugSystem::DrawWorldBounds() 
    {
        DrawRectangleLinesEx({0, 0, _game.world.GetSize().x, _game.world.GetSize().y}, _worldStroke, _worldColor);
    }

    void DebugSystem::DrawActor(Actor* actor) 
    {
        //Ignore actor layer, draw it here
        DrawActorPivotAtGlobal(actor);
        DrawActorCenterAtGlobal(actor);
        DrawActorPositionAtGlobal(actor);
        //
        DrawActorBoundsAtGlobal(actor);
        DrawActorExtentsAtGlobal(actor);
        
    }

    void DebugSystem::DrawActorPivotAtGlobal(Actor* actor)
    {

        //Pivot is not global, so add position to it
        RenderCircleAtPoint(
            Utilities::ToVector2(Vector3Add(actor->GetBoundsGlobal().GetPivot(), actor->GetPosition())),
            _centerRadius, 
            _actorColorPrimary, 
            "Actor Pivot");
    }


    //TODO: Remove this after testing?
    void DebugSystem::DrawActorCenterAtGlobal(Actor* actor) 
    {
         RenderCircleAtPoint(
            Utilities::ToVector2(actor->GetBoundsGlobal().GetCenter()),
             5.0f, 
             DARKGREEN, 
             "Actor Position");

    }
  
    //TODO: Remove this after testing?
    void DebugSystem::DrawActorPositionAtGlobal(Actor* actor) 
    {
        RenderCircleAtPoint(
            Utilities::ToVector2(actor->GetPosition()),
             5.0f, 
             DARKGREEN, 
             "Actor Position");

    }

     void DebugSystem::DrawActorBoundsAtGlobal(Actor* actor) 
    {
         RenderBoxAtRectangle
        (
            {
                actor->GetPosition().x - (actor->GetScaledSize().x)/2,
                actor->GetPosition().y - (actor->GetScaledSize().y)/2,
                actor->GetScaledSize().x ,
                actor->GetScaledSize().y 
            }, 
            10.0f, 
            _actorColorPrimary,
            "Actor Bounds (Global)"
        );

    }




    void DebugSystem::DrawActorExtentsAtGlobal(Actor* actor) 
    {
        auto boundsGlobal = actor->GetBoundsGlobal();

        RenderCircleAtPoint
            (
                Utilities::ToVector2(boundsGlobal.GetMin()), 
                5, 
                RED, 
                "Min"
            );

          RenderCircleAtPoint
            (
                Utilities::ToVector2(boundsGlobal.GetMax()), 
                5, 
                RED, 
                "Max"
            );

    }

    


    /////////////////////////////////////////////////////////////////////
    // JUST DRAWING ACTUAL PIXELS BELOW
    ////////////////////////////////////////////////////////////////////
     void DebugSystem::RenderCrosshairsAtRectangleCenter(Rectangle rectangle, float scale, float thick, Color color)
    {
        RenderCrosshairsAtRectangleCenter(rectangle, scale, thick, color, "");

    }

    void DebugSystem::RenderCrosshairsAtRectangleCenter(Rectangle rectangle, float scale, float thick, Color color, const char* label)
    {
        //HORIZONTAL - TODO: Draw from mid left to mid right
        DrawLineEx(
            {rectangle.x + (rectangle.width / 2) * (1 - scale), 
            rectangle.y + rectangle.height/2},
            {rectangle.x + (rectangle.width / 2) * (1 + scale), 
            rectangle.y + rectangle.height/2}, 
            thick, 
            color);
        
        //VERTICAL - TODO: draw from mid top to mid bottom
        DrawLineEx(
            {rectangle.x + rectangle.width/2, 
            rectangle.y + (rectangle.height / 2) * (1 - scale)},
            {rectangle.x + rectangle.width/2, 
            rectangle.y + (rectangle.height / 2) * (1 + scale)}, 
            thick, 
            color);

        if (!Utilities::IsNullOrEmpty(label))
        {
            DrawText(label, 
            (rectangle.x + rectangle.width/2) + _fontPositionOffset.x, 
            (rectangle.y + rectangle.height/2) + _fontPositionOffset.y, 
            _labelFontSize, 
            color);
        }
    }

    void DebugSystem::RenderBoxAtRectangle(Rectangle rectangle, float thick, Color color)
    {
        RenderBoxAtRectangle(rectangle, thick, color, nullptr);
    }

    void DebugSystem::RenderBoxAtRectangle(Rectangle rectangle, float thick, Color color, const char* label)
    {
        DrawRectangleLinesEx(rectangle, thick, color);
        if (!Utilities::IsNullOrEmpty(label))
        {
            DrawText
            (
                label, 
                rectangle.x + rectangle.width + _fontPositionOffset.x, 
                rectangle.y + rectangle.height + _fontPositionOffset.y, 
                _labelFontSize, 
                color
            );
        }
    }

    void DebugSystem::RenderCircleAtPoint(Vector2 point, float radius, Color color)
    {
        RenderCircleAtPoint(point, radius, color, "");
    }

    void DebugSystem::RenderCircleAtPoint(Vector2 point, float radius, Color color, const char* label)
    {
        DrawCircleV(point, radius, color);
        if (!Utilities::IsNullOrEmpty(label))
        {
            DrawText(label, point.x + _fontPositionOffset.x, point.y + _fontPositionOffset.y, _labelFontSize, color);
        }
    }
} 
