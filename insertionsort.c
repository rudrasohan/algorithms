#include <stdio.h>

int main()
{
	int n,i,j,key=0;
	printf("Enter the Length of the Array\n");
	scanf("%d",&n);
	int a[n];

	printf("\nEnter Elements\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d,",&a[i]);
	}
	printf("\n");

	printf("Unsorted Array\n");
	for (i = 0; i < n; i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");

	for (j = 1; j < n; j++)
	{
		i = j - 1;
		key = a[j];
		while(i>=0 && a[i]>key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key; 
	}
	printf("Sorted Array\n");
	for (i = 0; i < n; i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	return 0;
}