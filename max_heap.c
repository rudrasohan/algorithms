#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// main function to do heap sort
void max_heap(int arr[], int n)
{
	int i;
    // Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 /*
    // One by one extract an element from heap
    for (i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }*/
}
void printArray(int arr[], int n)
{
	int i;
    for (i=0; i<n; ++i)
        printf("%d,",arr[i]);
    printf("\n");
}
int main()
{
	int n,i;
	printf("Enter no of elemets\n");
	scanf("%d",&n);
	int arr[n];
	for(i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n");
	printf("Unsorted\n");
	printArray(arr,n);
	max_heap(arr,n);
	printf("Max_Heaped\n");
	printArray(arr,n);
	return 0;
}