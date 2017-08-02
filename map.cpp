#include <bits/stdc++.h>//#include <map>
using namespace std;


int main() 
{
    std::map<std::string/*key data type*/, std::string/*value data type*/>  MyMap;

	int n;
	string t1,t2;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >>t1;
		cin >>t2;
		MyMap[t1] = t2;
	
	}
	string a[2*n];
	int count = 0;
	
	while(cin >> a[count])
        count++;
	for (int i = 0; i < count; ++i)
	{
	
		if(MyMap[a[i]] == "")
			cout <<"Not found\n";
		else
			cout <<a[i]<<"="<<MyMap[a[i]]<<endl;
	}

    return 0;
}
