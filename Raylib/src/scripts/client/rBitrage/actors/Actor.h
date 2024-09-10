
#pragma once
#include <raylib.h>
#include <guiddef.h>
//
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


        //KEEP AS VIRTUAL...

        virtual void OnInitialize();
        virtual void OnFixedUpdate(float fixedDeltaTime);
        virtual void OnFrameUpdate(float deltaTime);
        virtual void OnFrameRender();


        //MANY BELOW *MAYBE* DON'T NEED TO BE VIRTUAL? (pUT IN 2 GROUPS, YES/NO AND CHANGE IT)

        virtual Vector3 GetPosition() const;
        virtual void SetPosition(const Vector3& position);
        
        virtual Vector3 GetRotation() const;
        virtual void SetRotation(const Vector3 &position);

        virtual const char* GetName() const;
        virtual void SetName(const char* name);

        virtual Game& GetGame() const;
        virtual Transform& GetTransform();


        //
        virtual float GetOpacity();
        virtual void SetOpacity(float opacity);

        //for gizmos
        virtual bool GetIsDebug() const;
        virtual void SetIsDebug(bool isDebug);

        //
        virtual Bounds GetBounds();
        virtual FrameRenderLayer GetFrameRenderLayer() const;

   


        //NOT VIRTUAL
        //for comparison
        GUID GetInstanceId();

        bool operator==(const Actor& other) const;


    protected:
        const char *_assetKey;
        FrameRenderLayer _frameRenderLayer;
        Game& _game;
        Transform _transform;
        Vector3 _size = {1, 1, 1};


    private:
        GUID _instanceId;
        bool _isDebug;
        float _opacity;
        const char * _name;
        Bounds _bounds;
    
        
    };
   
}