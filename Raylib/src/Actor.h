
#pragma once
#include <raylib.h>
#include "Game.h"
#include "Bounds.h"
#include "FrameRenderLayer.h"
#include "Transform.h"
#include "Utilities.h"

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Actor
    {
    public:
        Actor();
        Actor(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
        virtual ~Actor();

        virtual void OnInitialize();
        virtual void OnFixedUpdate(float fixedDeltaTime);
        virtual void OnFrameUpdate(float deltaTime);
        virtual void OnFrameRender();

        virtual Vector3 GetPosition() const;
        virtual void SetPosition(const Vector3& position);
        
        virtual Vector3 GetRotation() const;
        virtual void SetRotation(const Vector3 &position);

        virtual void SetPivot(const Vector3& pivot);
        virtual Vector3 GetPivot() const;

        virtual const char* GetName() const;
        virtual void SetName(const char* name);

        //
        virtual Vector3 GetSize() const;
        virtual void SetSize(const Vector3 &size);

        //
        virtual float GetOpacity();
        virtual void SetOpacity(float opacity);

        //for gizmos
        virtual bool GetIsDebug() const;
        virtual void SetIsDebug(bool isDebug);

        //
        virtual Bounds GetBounds() const;
        virtual FrameRenderLayer GetFrameRenderLayer() const;

    protected:
    
        Game& _game;
        Transform _transformation;
        Vector3 _size;
        Vector3 _pivot;
        FrameRenderLayer _frameRenderLayer;

    private:
        bool _isDebug;
        const char * _name;
        float _opacity;
        
    };
   
}