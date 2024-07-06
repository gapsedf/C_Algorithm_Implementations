#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
int hex_to_decimal();
int pow();

// Stack frame of main method
int main()
{
    int hex=0x3BA4;

    printf("Decimal eq. of %x is %d",hex,hex_to_decimal(hex));


    return 0;
}

// Function Roots When called
int hex_to_decimal(int hex)
{
    int counter=0;
    int hexct = hex;

    while(hexct!=0)
    {
        counter++;
        hexct/=16;
    }

    int dec=0;

    for(int i=0;i<counter;i++)
    {
        dec += pow(16,i)*(hex%16);
        hex/=16;
    }

    return dec;
}

int pow(int r, int n)
{
    int t=1;
    for(int i=0;i<n;i++)
    {
        t*=r;
    }
    return t;
}
