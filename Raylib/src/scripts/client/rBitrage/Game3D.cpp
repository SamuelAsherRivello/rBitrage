#include "client/rBitrage/Game3D.h"

namespace RMC::rBitrage 
{
    Game3D::Game3D() : Game () 

    {
        cameraSystemMode = CameraSystemMode::Cam3D;
    }

    Game3D::~Game3D() 
    {

    }


    void Game3D::Initialize() 
    {
        if (GetIsInitialized())
        {
            return;
        }
        Game::Initialize();

    }

    void Game3D::Initialized() 
    {
       if (GetIsInitialized())
        {
            return;
        }

        Game::Initialized();
    }

}