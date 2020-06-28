
#include <windows.h>
#include <iostream>


int main( int argc, char *argv[], char * envp[] ) 
{
    
    typedef double(*volumeOfCone)( float, float);
    volumeOfCone p_fun;
    double cone_volume = 0;

    if( 3 != argc ) 
    {
        std::cout<< "\n" ;
        std::cout<<" Invalid Input."<< std::endl;
        std::cout<<" INPUT AS : exe_name <float_input_1> <float_input_2>";
        std::cout<< "\n";
        return(0);
    }

    HINSTANCE hDll = LoadLibrary("./Server.dll");

    p_fun = (volumeOfCone)GetProcAddress(hDll, TEXT("GetConeVolume"));

    cone_volume = p_fun( atof(argv[1]), atof(argv[2]));

    std::cout<<"\n\n";

    std::cout<< "Volume Of Cone = " << cone_volume << " unit cube" << std::endl;

    return(0);

}
