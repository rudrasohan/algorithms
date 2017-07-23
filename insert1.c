#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *  ar) 
{
   
    int i,j,k,flag =0;
for(k = ar_size-1;k>=0;k--)
{
     int e = ar[k];
    for(i=ar_size-1;i>=0;i--)
    {
        if(ar[i-1]>=e)
        {
            ar[i] = ar[i-1];
        }
        else
        {
            ar[i] = e;
            flag = 1;
        }    
       
        if(flag == 1)
            break;
    }
    for(j=0;j<ar_size;j++)
       {
           printf("%d ",ar[j]);
       }
       printf("\n");
} 

}
int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    insertionSort(_ar_size, _ar);
    return 0;
}
