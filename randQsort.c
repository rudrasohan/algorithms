/* C implementation QuickSort */
#include <stdio.h>
#include <stdlib.h>
// A utility function to swap two elements
time_t t;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[low];    // pivot
    int i = low,j;  // Index of smaller element
    srand((unsigned) time(&t));
    int pv = low + rand() % (high-low+1);
    pivot = arr[pv];
    swap(&arr[pv],&arr[low]);
    for (j = low+1; j <= high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[low]);
    return i;
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
       // int i;
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
       	quickSort(arr, pi + 1, high);
       /* for (i=low; i < high; i++)
        printf("%d ", arr[i]);
        printf("\n");*/
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
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
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
   	printArray(arr, n);
    return 0;
}