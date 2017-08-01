#include <bits/stdc++.h>
using namespace std;


int main() {
    int v,n;
    cin >> v;
    cin >> n;
    int a[n];
    int i,l=-1,h=n;
    for(i=0;i<n;i++)
        cin >> a[i];
    while(h>l)
    {
        int mid = (h+l)/2;
        if(a[mid]==v)
        {    
            cout <<mid;
            break;
        }    
        if(a[mid]>v)
            h = mid;
        if(a[mid]<v)
            l = mid;
    }
    return 0;
}