#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void buck_sort(float x[],int n)
{
	vector <float> b[n];
	int i,j,k;
	float key;
	for(i = 0;i < n;i++)
	{
		int t = x[i]*n;
		//cout <<t<<endl;
		b[t].push_back(x[i]);
	}
	
	for(k = 0;k<n;k++)
	{
		sort(b[k].begin(),b[k].end());
	}
	for(k = 0;k<n;k++)
	{
		if(b[k].size() != 0)
		{
			for(i=0;i<b[k].size();i++)
			{
				cout << b[k][i]<<" ";
				
			}
		}
	}

}

int main()
{
	int n;
	cin >>n;
	float arr[n];
	for(int i = 0;i<n;i++)
	{
		cin >>arr[i];
	}
	buck_sort(arr,n);
	return 0;
}