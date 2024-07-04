#include <stdio.h>
#include <stdlib.h>


void merge_sort(int *a,int p, int r)
{
if(p>=r)
{
return;
}

int q=(p+r)/2;
merge_sort(a,p,q);
merge_sort(a,q+1,r);
merge(a,p,q,r);
}

void merge(int *a,int p, int q, int r)
{
int nl= q-p+1;
int nr= r-q;

int L[nl];
int R[nr];

for(int i=0;i<nl;i++)
{
    L[i] = a[i+p];
}

for(int j=0;j<nr;j++)
{
    R[j] = a[q+1+j];
}

int i=0;
int j=0;
int k=p;

while(i<nl && j<nr)
    {
        if(L[i]<=R[j])
            {
                a[k]=L[i];
                i++;
            }else
            {
                a[k]=R[j];
                j++;
            }
        k++;
    }

while(i<nl)
    {
        a[k] = L[i];
        i++;
        k++;
    }

while(j<nr)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}


int main()
{
    int a[] = {[9]=2,[10]=4,[11]=6,[12]=7,[13]=1,[14]=2,[15]=3,[16]=5,[25]=0};
    merge_sort(a,9,16);

    for(int i=0;i<25;i++)
    {
    printf("%d ",a[i]);
    }



    return 0;
}
