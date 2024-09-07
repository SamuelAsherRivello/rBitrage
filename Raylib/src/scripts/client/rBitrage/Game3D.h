
#pragma once
#include "client/rBitrage/core/Game.h"

namespace RMC::rBitrage 
{
    class Game3D : public Game
    {
        public:

            //Constructor
            Game3D();
            ~Game3D();

            //Lifecycle
            void Initialize() override;
            void Initialized() override;

        private:

    };
}

