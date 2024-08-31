#include "System.h"
#include "Game.h"
#include <raylib.h>
#include <iostream>

System::System(Game& game): _game (game) 
{
   
}


System::~System() 
{
    std::cout << "ok " << std::endl;
}


void System::OnInitialize() 
{

}
void System::OnInitialized() 
{

}


void System::OnFixedUpdate(float fixedDeltaTime) 
{

}


void System::OnFrameUpdate(float deltaTime) 
{

}


void System::OnFrameRender(const FrameRenderLayer& frameRenderLayer) 
{

}