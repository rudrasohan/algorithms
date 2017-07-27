#include <stdio.h>

int power_rec(int n,int a)
{
	if(n == 0)
		return 1;
	else if(n == 1)
		return a;
	else
	{
		if((n%2) == 0)
		{	
			int e = power_rec(n/2,a);
			return(e*e);
		}	
		else
		{
			int o = power_rec((n-1)/2,a);	
			return(o*o*a);
		}
	}
}

int main()
{
	int a,n;
	printf("Enter the number and power\n");
	scanf("%d%d",&a,&n);
	int pow = power_rec(n,a);
	printf("Ans = %d\n",pow);
}

