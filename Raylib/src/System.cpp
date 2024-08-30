#include "System.h"
#include "Game.h"
#include <raylib.h>

System::System(Game& game): _game (game) {
   
}
System::~System() {
   
}

void System::OnInitialize() {
}

void System::OnFixedUpdate(float fixedDeltaTime) {
}

void System::OnFrameUpdate(float deltaTime) {
}

void System::OnFrameRender(const FrameRenderLayer& frameRenderLayer) {

}