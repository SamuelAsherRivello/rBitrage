
#pragma once
#include <raylib.h>
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/types/Bounds.h"
#include "client/rBitrage/types/FrameRenderLayer.h"
#include "client/rBitrage/types/Transform.h"
#include "client/rBitrage/utilities/Utilities.h"
#include <iostream>

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Actor
    {
    public:
        Actor(Game& game, const char *_assetKey, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
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
        const char *_assetKey;
        FrameRenderLayer _frameRenderLayer;
        Game& _game;
        Transform _transformation;
        Vector3 _size;
        Vector3 _pivot;

    private:
        bool _isDebug;
        float _opacity;
        const char * _name;
        
    };
   
}