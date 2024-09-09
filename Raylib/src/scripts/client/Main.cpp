#include "client/rBitrageDemos/demo01Raylib/Demo01Raylib.h"
#include "client/rBitrageDemos/demo02rBitrage/Demo02rBitrage.h"
#include "client/rBitrageDemos/demoXXShapes/DemoXXShapes.h"
#include "client/rBitrageDemos/demoXXOrbitGame2D/DemoXXOrbitGame2D.h"
#include "client/rBitrageDemos/demoXXStressTest2D/DemoXXStressTest2D.h"
#include "client/rBitrageDemos/demoXXStressTest3D/DemoXXStressTest3D.h"

int main()
{


    /// DEMOS - WORKING
    //return Demo01Raylib();
    //return Demo02rBitrage();
    //return DemoXXShapes();        
    //return DemoXXStressTest2D();  

    /// DEMOS - WORK IN PROGRESS
    //return DemoXXOrbitGame2D();                        
    return DemoXXStressTest3D();
    
    /// DEMOS - BROKEN
    //return gameCreateMain2D();
    //return gameCreateSpheres2D(); 
    //return gameCreateSpheres3D(); 
    return 0;
}