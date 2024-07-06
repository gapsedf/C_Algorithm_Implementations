#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int dec_to_hex();
int pow();

// Stack frame of main method
int main()
{
    int dec = 15268;

    printf("%x",dec_to_hex(dec));

    return 0;
}

// Function roots
int dec_to_hex(int dec)
{
    int counter =0;
    int decct = dec;
    while(decct!=0)
    {
        counter++;
        decct/=16;
    }
    int hex = 0;

    for(int i=0;i<counter;i++)
    {
        hex+=pow(16,i)*(dec%16);
        dec/=16;
    }

    return hex;
}

int pow(int r, int n)
{
    int t = 1;
    for(int i=0;i<n;i++)
    {
        t*=r;
    }

    return t;
}
