#include "Actor.h"
#include "Utilities.h"
#include <raylib.h>
#include <iostream>
#include "Game.h"



namespace RMC::rBitrage 
{
    //1
     Actor::Actor() : 
        _game(Game()),
        _opacity(1.0f),
        _frameRenderLayer(FrameRenderLayer::Camera2D)
        {

        }

    //2
    Actor::Actor(Game& game, const FrameRenderLayer& frameRenderLayer) 
        : 
        _game(game),
         _opacity(1.0f),
          _frameRenderLayer(frameRenderLayer)
    {
        SetIsDebug(false);
        SetPivot({0.5f, 0.5f, 0.5}); //center pivot by default
        SetName(typeid(this).name());
        SetPosition({0,0,0});
        SetSize({100, 100, 0});
    }

    Actor::~Actor() 
    {
    
    }

    void Actor::OnInitialize() 
    {
    }


    void Actor::OnFixedUpdate(float fixedDeltaTime) 
    {
    }

    void Actor::OnFrameUpdate(float deltaTime) 
    {
    }

    void Actor::OnFrameRender() 
    {
    }


    const char* Actor::GetName() const 
    {
        return _name;
    }

    //TODO: I'm recalling this in child constructors. I'd like to call it only in the parent
    //and have the solution 'know' the name of the child-most name
    void Actor::SetName(const char* name) 
    {
        _name = name;
    }


    Vector3 Actor::GetPosition() const 
    {
        return _transformation.Position;
    }

    void Actor::SetPosition(const Vector3& position) 
    {
        _transformation.Position = position;
    }

    Vector3 Actor::GetRotation() const 
    {
        return _transformation.Rotation;
    }

    void Actor::SetPivot(const Vector3& pivot) 
    {
        _pivot = Utilities::ToVector3Normalized(pivot);
    }

    Vector3 Actor::GetPivot() const 
    {
        return _pivot;
    }
    

    void Actor::SetRotation(const Vector3& position) 
    {
        _transformation.Rotation = position;
    }

    bool Actor::GetIsDebug() const 
    {
        return _isDebug;
    }

    void Actor::SetIsDebug(bool isDebug) 
    {
        _isDebug = isDebug;
    }


    float Actor::GetOpacity()
    {
        return _opacity;
    }

    void Actor::SetOpacity(float opacity)
    {
         // Clamp the opacity value between 0 and 1
         _opacity = Utilities::ToFloatNormalized(opacity);
    }

    Vector3 Actor::GetSize() const 
    {
        return _size;
    }

    void Actor::SetSize(const Vector3& size) 
    {
        _size = size;
    }

    Bounds Actor::GetBounds() const  
    {
        return {
                    {_transformation.Position.x, _transformation.Position.y, _transformation.Position.z}, 
                    {_size.x, _size.y, _size.z}
                };
    }

    FrameRenderLayer Actor::GetFrameRenderLayer() const  
    {
        return _frameRenderLayer;
    }
}