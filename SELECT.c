#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int low,int high)
{
    int i;
    printf("PRINT%d%d\n",low,high);
    for (i=low; i <=high; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void sort(int arr[],int low,int high)
{
    printf("SORT%d%d\n",low,high);
    int i,j,key;
    for (j = low+1; j <= high; j++)
    {
        i = j - 1;
        key = arr[j];
        while(i>=low && arr[i]>key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key; 
    }
    //printf("END%d",a[high]);
    printArray(arr,low,high);
}



int SELECT(int arr[],int low,int high)
{
    printf("SEL%d%d\n",low,high);
    if(low == high)
        return arr[low];
    else
    {
    int i,k=0;
    int size = high-low+1;
    int tsize = (size+4)/5;
    int q = size%5;
    int t[tsize];
    for(i = low;i<size-q;i +=5)
    {
        sort(arr,i,i+4);
        t[k] = arr[i+2];
        k++;
    }
    //printf("%d\n",i);
    if(size%5 != 0)
    {
        sort(arr,(i),high);
        t[k] = arr[i+(size%5)/2];
    }
    //printArray(t,0,tsize-1);
    return SELECT(t,0,tsize-1);
}
}

int search(int arr[],int low,int high,int pivot)
{
    int i;
    for(i = low ;i <= high;i++)
    {
        if(arr[i] == pivot)
            return i;
    }
}
int partition (int arr[], int low, int high)
{
    printf("PART%d%d\n",low,high);
    int pivot;    // pivot
    int i = low,j;  // Index of smaller element
    pivot = SELECT(arr,low,high);
    printf("Pivot%d\n",pivot);
    int pv = search(arr,low,high,pivot);
    swap(&arr[pv],&arr[low]);
    for (j = low+1; j <= high; j++)
    {
        printArray(arr,low,high);
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[low]);
    printArray(arr,low,high);
    return i;
}

int quickSelect(int arr[], int low, int high,int i)
{
    if(high>=low)
    {
        printf("QSEL%d%d%d\n",low,high,i);
       if(high == low)
            return arr[high];

        int r = partition(arr, low, high);
        printf("R%dI%d\n",r,i);
        int k = r - low+1;
        if(i == k)
            return arr[k+low-1];
        if(i < k)
           return quickSelect(arr, low, r - 1,i);
        if(i > k)
           return quickSelect(arr, r + 1, high,i-k);
}
       /* for (i=low; i < high; i++)
        printf("%d ", arr[i]);
        printf("\n");*/
   
}

int main()
{
  int n;
    printf("Enter the size\n");
    scanf("%d",&n);
    int i=0,arr[n];
    printf("Enter Elements\n");
    for (i = 0; i < n; i++)
    {
      scanf("%d",&arr[i]);
    }
    printf("\nEnter the which smallest element you want ==> ");
    int ele;
    while(ele != 99)
    {
    scanf("%d",&ele);
    int num = quickSelect(arr, 0, n-1,ele);
    printf("Kth Smallest Element");
    printf("\n%d\n",num);
}
  return 0;
}