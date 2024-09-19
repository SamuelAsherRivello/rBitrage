#include "client/rBitrageDemos/demo01Raylib/Demo01Raylib.h"
#include "client/rBitrageDemos/demo02rBitrage/Demo02rBitrage.h"
#include "client/rBitrageDemos/demoXXShape2D/DemoXXShape2D.h"
#include "client/rBitrageDemos/demoXXBall3D/DemoXXBall3D.h"

//#include "client/rBitrageDemos/demoXXOrbitGame2D/DemoXXOrbitGame2D.h"

/*

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
    //return DemoXXShape2D(); 
    //return DemoXXBall3D();

    // OTHER DEMOS - BROKEN
    //return DemoXXOrbitGame2D();                        

    //return DemoXXModel3D();
    
    // OTHER DEMOS - BROKEN
    //return gameCreateMain2D();
    //return gameCreateSpheres2D(); 
    //return gameCreateSpheres3D(); 
    return 0;
};