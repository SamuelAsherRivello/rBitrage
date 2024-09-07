#include "client/rBitrage/Game2D.h"

namespace RMC::rBitrage 
{
    Game2D::Game2D() : Game () 

    {
        cameraSystemMode = CameraSystemMode::Cam2D;
    }

    Game2D::~Game2D() 
    {

    }


    void Game2D::Initialize() 
    {
        if (GetIsInitialized())
        {
            return;
        }
        Game::Initialize();

    }

    void Game2D::Initialized() 
    {
       if (GetIsInitialized())
        {
            return;
        }

        Game::Initialized();
    }

}