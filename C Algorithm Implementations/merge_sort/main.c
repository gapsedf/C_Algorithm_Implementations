#include <stdio.h>
#include <stdlib.h>


// Function Prototypes

int* createarray();
void sorting_two();
void merge_sort();
void printarray();


// Main Function

int main()
{
    /*
    Merge Sort, Divide & Conqueror method.
    Using functions and pointers respectively.
    */

    int size = -1;

    while(size<0)
    {
    printf("Enter the size of array: ");
    scanf("%d",&size);
    }


    int *Main_Array = createarray(size);


    int q = -1;

    while(q<0)
    {
    printf("Enter the between point: ");
    scanf("%d",&q);
    }

    sorting_two(Main_Array,size,q);

    int p=0;
    //int q=4;// Between Point
    int r=size-1;

    merge_sort(Main_Array,p,q,r);

    printarray(Main_Array,size);

    free(Main_Array);

    return 0;
}

// Function Roots
int* createarray(int size)
{

int *A= (int *) malloc(sizeof(int)*size);

printf("Enter the array values \n");
for(int i=0;i<size;i++)
{
    printf("Element [%d]",i);
    scanf("%d",&A[i]);
}

return A;
}

void sorting_two(int A[], int SizeArr, int q)
{
    for(int m=0;m<=q;m++)
    {
        for(int n=m+1;n<=q;n++)
        {
            if(A[m]>A[n])
            {
                int temp;
                temp = A[m];
                A[m] = A[n];
                A[n]=temp;
            }
        }
    }

    for(int m=q+1;m<SizeArr;m++)
    {
        for(int n=m+1;n<SizeArr;n++)
        {
            if(A[m]>A[n])
            {
                int temp;
                temp = A[m];
                A[m] = A[n];
                A[n]=temp;
            }
        }
    }


}


void merge_sort(int A[], int p, int q, int r)
{

    int i;
    int j;

    int SizeLeft = q-p+1;
    int SizeRight = r-q;

    //Sub_Array Creation
    int Left_Sub_Array[SizeLeft];
    int Right_Sub_Array[SizeRight];

    for(i=0;i<SizeLeft;i++)
    {
    Left_Sub_Array[i] = A[p+i];
    }

    for(j=0;j<SizeRight;j++)
    {
    Right_Sub_Array[j] = A[q+1+j];
    }

    i = 0;
    j = 0;
    int k = p;

    while(i<SizeLeft && j<SizeRight)
    {
        if( Left_Sub_Array[i]<Right_Sub_Array[j])
        {
            A[k] = Left_Sub_Array[i];
            i = i + 1;
        }else
        {
            A[k] = Right_Sub_Array[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while(i<SizeLeft)
    {
        A[k] = Left_Sub_Array[i];
        i = i + 1;
        k = k + 1;
    }

    while(j<SizeRight)
    {
        A[k] = Right_Sub_Array[j];
        j = j + 1;
        k = k + 1;
    }
}

void printarray(int A[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",A[i]);
    }
}
