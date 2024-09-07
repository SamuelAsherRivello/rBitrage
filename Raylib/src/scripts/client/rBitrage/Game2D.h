
#pragma once
#include "client/rBitrage/core/Game.h"

namespace RMC::rBitrage 
{
    class Game2D : public Game
    {
        public:

            //Constructor
            Game2D();
            ~Game2D();

            //Lifecycle
            void Initialize() override;
            void Initialized() override;

        private:

    };
}