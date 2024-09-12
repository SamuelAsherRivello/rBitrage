#include "client/rBitrage/actors/Actor.h"
#include "Actor.h"


namespace RMC::rBitrage 
{
    Actor::Actor(Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) :
        _game (game), 
        _assetKey (assetKey),
        _frameRenderLayer (frameRenderLayer),
        _bounds(new Bounds())
    {
        _opacity = 1;
        _instanceId = GUID();

        //
        SetIsDebug(false);
        SetName(typeid(this).name());
        SetPosition({0,0,0});
       
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
    Game& Actor::GetGame() const
    {
        return _game;
    }


    Vector3 Actor::GetPosition() const  { return _transform.Position; }
    void Actor::SetPosition(const Vector3& value)  { _transform.Position = value; }

    Vector3 Actor::GetRotation() const  { return _transform.Rotation; }
    void Actor::SetRotation(const Vector3& value)  { _transform.Rotation = value; }

    Vector3 Actor::GetScale() const  { return _transform.Scale; }
    void Actor::SetScale(const Vector3& value)  { _transform.Scale = value; }




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


    Bounds& Actor::GetBounds() 
    {
        return *_bounds;
    }


    FrameRenderLayer Actor::GetFrameRenderLayer() const  
    {
        return _frameRenderLayer;
    }



    GUID Actor::GetInstanceId() const
    {
        return _instanceId;
    }

    bool RMC::rBitrage::Actor::operator==(const Actor& other) const {
        return _instanceId == other._instanceId;
    }
}