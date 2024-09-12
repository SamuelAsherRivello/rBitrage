#include "client/rBitrageDemos/demo01Raylib/Demo01Raylib.h"
#include "client/rBitrageDemos/demo02rBitrage/Demo02rBitrage.h"
#include "client/rBitrageDemos/demoXXShapes/DemoXXShapes.h"
#include "client/rBitrageDemos/demoXXStressTest2D/DemoXXStressTest2D.h"
//#include "client/rBitrageDemos/demoXXOrbitGame2D/DemoXXOrbitGame2D.h"

/*
#include "client/rBitrageDemos/demoXXStressTest3D/DemoXXStressTest3D.h"
#include "client/rBitrageDemos/demoXXModel3D/DemoXXModel3D.h"
*/


/*

    This is the main entry point for the application.
    Uncomment exactly one demo below to see it.

*/
int main()
{
    /// PRIMARY DEMOS - WORKING WELL
    //return Demo01Raylib();
    return Demo02rBitrage();

    // SECONDARY DEMOS - WORKING WELL
    //return DemoXXShapes(); 
    //return DemoXXStressTest2D();  

    // OTHER DEMOS - BROKEN
    //return DemoXXOrbitGame2D();                        
    //return DemoXXStressTest3D();
    //return DemoXXModel3D();
    
    // OTHER DEMOS - BROKEN
    //return gameCreateMain2D();
    //return gameCreateSpheres2D(); 
    //return gameCreateSpheres3D(); 
    return 0;
};