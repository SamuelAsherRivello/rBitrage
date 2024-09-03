
#pragma once
#include <raylib.h>
#include "Game.h"
#include "Bounds.h"
#include "FrameRenderLayer.h"
#include "Transform.h"

namespace RMC::rBitrage 
{
    // NEEDED? Forward declaration of Game class
    class Game;

    class Actor
    {
    public:
        Actor(Game& game, const FrameRenderLayer& frameRenderLayer = FrameRenderLayer::Camera2D);
        virtual ~Actor();

        virtual void OnInitialize();
        virtual void OnFixedUpdate(float fixedDeltaTime);
        virtual void OnFrameUpdate(float deltaTime);
        virtual void OnFrameRender();

        Vector3 GetPosition() const;
        void SetPosition(const Vector3& position);
        
        Vector3 GetRotation() const;
        void SetRotation(const Vector3 &position);

        void SetPivot(const Vector3& pivot);
        Vector3 GetPivot() const;

        const char* GetName() const;
        void SetName(const char* name);

        //
        Vector3 GetSize() const;
        virtual void SetSize(const Vector3 &size);
        float GetOpacity();
        void SetOpacity(float opacity);
        //
        Bounds GetBounds() const;
        FrameRenderLayer GetFrameRenderLayer() const;

    protected:
        FrameRenderLayer _frameRenderLayer;
        Game& _game;
        Transform _transformation;
        Vector3 _size;
        Vector3 _pivot;

    private:
        float _opacity;
        const char * _name;
        
    };
   
}