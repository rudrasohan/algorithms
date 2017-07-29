#include <bits/stdc++.h>

using namespace std;

int gemstones(vector <string> arr)
{
    int l = arr.size();
    int i,j,k,flag=1;
    //cout << arr[0][1]<<endl;/*
    string str;
    //cin >> str;
    //arr.push_back(str);
    //l = arr.size();
    //cout << arr[3]<<endl;
    int gem[l][26];
    int final=0;
    for (i = 0; i < l; i++)
    {
    	for(j = 0;j<26;j++)
    	{
    		gem[i][j] = 0;
    	}
    }
    for(i=0;i<l;i++)
    {
    	str = arr[i];
    	int count = arr[i].length();
    	int ch;
    	for (j=0;j < count; j++)
    	{
   			ch = str[j] - 'a';
   			gem[i][ch] = gem[i][ch]+1;
   			ch = 0;
    	}
    }
    for (i = 0; i < 26; i++)
    {
    	int key = gem[0][i];
    	for (j = 1; j < l; j++)
    	{
    		if(gem[j][i]!=key)
    		{
    			if(gem[j][i] == 0)
    				flag = 0;
    			else
    			{
    				if(key>gem[j][i])
    					key = gem[j][i];
    			}
    		}
    	}
    	if(flag == 1)
    		final = final + key;
    	else
    		flag = 1;
    }
    //cout <<l <<endl;
    return final;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
