#include <bits/stdc++.h>
using namespace std;

void sorting(vector<string> v,int k,int n,string type)
{
  int k=0,i=0;
  while(k<key)
  {
    i=v[0].find(" ",i);
    k++;
  }
  int pos1 = i;
  int pos2 = v[0].find(" ",i+1);
  string s[n];
  int a[n];
  for(int i = 0;i<n;i++)
  {
    s[i] = v[i].substr(pos1+1,(pos2-pos1-1));
    a[i] = stoi(s[i]);
  }
  

}
nt spac = inputString.find(" " , 0);
int main()
{
  int n;
  cin>>n;
  cin.ignore(256, '\n');
  vector<string> v;
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    s = " "+s;
    v.push_back(s);
  }
  int key;
  cin>>key;
  cin.ignore(256, '\n');
  bool flag;
  cin>>flag;
  cin.ignore(256, '\n');
  string g;
  cin>>g;
  return 0;
}

//cin.ignore(256, '\n');
