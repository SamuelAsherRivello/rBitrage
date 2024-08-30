#include "client/games/orbitGame2D/OrbitGame2D.h"
#include "client/rBitrageDemos/demo01Raylib/Demo01Raylib.h"
#include "client/rBitrageDemos/demo02rBitrage/Demo02rBitrage.h"
#include "client/rBitrageDemos/demoXXShapes/DemoXXShapes.h"
#include "client/rBitrageDemos/demoXXStressTest2D/DemoXXStressTest2D.h"
#include "client/rBitrageDemos/demoXXStressTest3D/DemoXXStressTest3D.h"

int main()
{


    //Working
    //return Demo01Raylib();
    //return Demo02rBitrage();


    //WIP                           
    //return DemoXXShapes();        
    return DemoXXStressTest2D();  
    //return DemoXXStressTest3D();
    
    
    
    ///Broken
    //return OrbitGame2D();
    //return gameCreateMain2D();
    //return gameCreateSpheres2D(); 
    //return gameCreateSpheres3D(); 
    return 0;
}