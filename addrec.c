#include <stdio.h>

int a[6];
	
void sum(int n)
{
	if(n>=0)
	{	
		int k = 3;
		sum(n-1);
		int t = n;
		while(t>0)
		{
			a[k] = t%3;
			k--;
			t = t/3;
		}
		int j;
		for (j = 0; j < 4; j++)
		{
			printf("%d",a[j]);
		}
		printf("\n");
	}
	
}

int main()
{
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	sum(80);

}