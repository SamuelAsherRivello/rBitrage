
#pragma once
#include <raylib.h>
#include <iostream>
#include <string.h>
#include "client/rBitrageDemos/actors/Background2D.h"
#include "client/rBitrage/actors/Shape2D.h"
#include "client/rBitrage/types/ShapeDatas.h"
#include "client/rBitrage/core/Game.h"

namespace RMC::rBitrage 
{
    class Background2D : public Shape2D
    {
        public:
            Background2D(Game& game, Color color = RBITRAGE_BACKGROUND2D_DEFAULT_COLOR);
            virtual ~Background2D();

        private:
        };

}