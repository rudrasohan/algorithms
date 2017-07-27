#include <stdio.h>
int a[2][2] = {{1,1},{1,0}};
int I[2][2] = {{1,0},{0,1}};
int ans[2][2] = {{1,1},{1,0}};
void product(int b[][2],int k[][2])
{
	int c[2][2];
	c[0][0] = b[0][0]*k[0][0]+b[0][1]*k[1][0];
	c[0][1] = b[0][0]*k[0][1]+b[0][1]*k[1][1];
	c[1][0] = b[1][0]*k[0][0]+b[1][1]*k[1][0];
	c[1][1] = b[1][0]*k[0][1]+b[1][1]*k[1][1];
	ans[0][0] = c[0][0];
	ans[0][1] = c[0][1];
	ans[1][0] = c[1][0];
	ans[1][1] = c[1][1];
	//printf("mult%d %d %d %d\n",b[0][0],b[0][1],b[1][0],b[1][1]);
} 
void power_rec(int n)
{	

	if((n == 1)||(n==0))
		return;
	else
	{
		if((n%2) == 0)
		{	
			power_rec(n/2);
			//int e[2][2];
			product(ans,ans);
			//printf("even%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
			//product(a,a);
		}	
		else
		{
			power_rec((n-1)/2);	
			//int o[2][2];
			product(ans,ans);
			product(ans,a);
			//printf("odd%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
		}
	}
}

int main()
{
	printf("Enter the value of n\n");
	int n;
	scanf("%d",&n);
	if(n == 1)
	{
		printf("Ans: 0\n");
	}
	else
	{	
		power_rec(n-1);
		//printf("main %d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
		printf("Ans: %d\n",ans[0][1]);
	}
}