#include <studio.h>

int main()
{
    int nDevices();
    
    cudaGetDeviceCount(&nDevices)
    {
        for(int i=0 ; i<nDevices ; i ++)
        {
            cudaDeviceProp prop;
            cudaDeviceProperties(&prop, i);
            printf("Device Number %d\n"+i);
            printf("Device name %s\n"+prop.name);
            


        }

    }

}