#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> sorty(1000000000);
bool compare_it(string a,string b)
{
	int l1 = a.length();
	int l2 = b.length();
	if (l1>l2)
		return true;
	else if(l1 == l2)
	{
		if(a.compare(b)>=0)
			return true;
		else 
			return false;
	}
	else
		return false;
} 

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    vector<string> L(n1); 
    vector<string> R(n2);
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = sorty[l + i];
    for (j = 0; j < n2; j++)
        R[j] = sorty[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (compare_it(R[j],L[i]))//L[i] <= R[j]
        {
            sorty[k] = L[i];
            i++;
        }
        else
        {
            sorty[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        sorty[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        sorty[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);
 
        merge(l, m, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
       sorty[unsorted_i] = unsorted[unsorted_i];
    }/*
    int i,j;
    string key = "";

    for (j = 1; j < n; j++)
	{
		i = j - 1;
		key = unsorted[j];
		while(i>=0 && compare_it(unsorted[i],key))
		{
			unsorted[i+1] = unsorted[i];
			i--;
		}
		unsorted[i+1] = key; 
	}*/
    mergeSort(0, (n - 1));
	for (int i = 0; i < n; ++i)
	{
		cout << unsorted[i] << endl;
	}
    return 0;
}
