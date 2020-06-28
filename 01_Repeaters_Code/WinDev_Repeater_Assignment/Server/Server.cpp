
#pragma once

#include <windows.h>

#define MY_PI   3.1415926535 

BOOL DllMain( HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved )
{
    switch( dwReason )
    {
        case DLL_PROCESS_ATTACH:
            break;
        
        case DLL_THREAD_ATTACH:
            break;
        
        case DLL_THREAD_DETACH:
            break;
        
        case DLL_PROCESS_DETACH:
            break;
    }
    return(TRUE);
}


double GetConeVolume( float i_radius, float i_height)
{
    return ( MY_PI * i_radius * i_radius * ( i_height / 3 ) );
}

