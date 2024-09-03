#include "Actor3D.h"
#include "Actor.h"
#include "AssetLoaderSystem.h"
#include <raylib.h>
#include <iostream>
#include <string>
#include <string.h>

namespace RMC::rBitrage 
{
    Actor3D::Actor3D (Game& game, const char *assetKey, const FrameRenderLayer& frameRenderLayer) 
        : Actor (game, frameRenderLayer)
    {
        _assetKey = assetKey;

        //TODO: I call this **Again** eventhough parent does it
        // just to trigger building the texture. Can I remove this?
        SetSize({100, 100, 100});
    }

    Actor3D::~Actor3D() 
    {
        
    }

    void Actor3D::OnInitialize() {
        Actor::OnInitialize();
    }


    void Actor3D::OnFixedUpdate(float fixedDeltaTime) 
    {
        Actor::OnFixedUpdate(fixedDeltaTime);

          std::cout << "4, ActorSystem::OnFixedUpdate" << std::endl;
    }

    void Actor3D::OnFrameUpdate(float deltaTime) 
    {
        Actor::OnFrameUpdate(deltaTime);
    }

    void Actor3D::OnFrameRender() {

        Actor::OnFrameRender();

        std::cout << "4, ActorSystem::OnFrameRender" << std::endl;

        // TODO: Use transform.scale instead of size here (and also in 2d?)
        //NOTE: I **think** that size is relative to asset an scale is relative to world unites and you need both. Yes?
        DrawCube(_transformation.Position, _size.x, _size.y, _size.z, BLUE);
        DrawCircle3D(_transformation.Position, _size.x, _transformation.Rotation, 0, RED);

    }

    void Actor3D::SetSize(const Vector3& size) 
    {
        Actor::SetSize(size);

        //load 3d

    }
}