#include <stdio.h>

int main()
{
	int k = 0,i,j;
	int a[6];
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	for(i=0;i<81;i++)
	{
		k = 3;
		printf("%d:",i);
		int t = i;
		while(t>0)
		{
			a[k] = t%3;
			k--;
			t = t/3;
		}
		for (j = 0; j < 4; j++)
		{
			printf("%d",a[j]);
		}
		printf("\n");
	}	
	return 0;
}