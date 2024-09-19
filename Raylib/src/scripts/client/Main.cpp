#include "client/rBitrageDemos/demo01Raylib/Demo01Raylib.h"
#include "client/rBitrageDemos/demo02rBitrage/Demo02rBitrage.h"
#include "client/rBitrageDemos/demoXXShape2D/DemoXXShape2D.h"
#include "client/rBitrageDemos/demoXXBall3D/DemoXXBall3D.h"
#include "client/rBitrageDemos/demoXXOrbitGame2D/DemoXXOrbitGame2D.h"
#include "client/rBitrageDemos/demoXXModel3D/DemoXXModel3D.h"

/*
    Main entry point for the application
    Uncomment EXACTLY ONE demo below to run.
*/
int main()
{
    /// PRIMARY DEMOS - WORKING WELL
    //return Demo01Raylib();
    //return Demo02rBitrage();

    // SECONDARY DEMOS - WORKING WELL
    //return DemoXXShape2D(); 
    //return DemoXXBall3D();
    return DemoXXModel3D();

    // OTHER DEMOS - BROKEN
    //return DemoXXOrbitGame2D();                        

    return 0;
};