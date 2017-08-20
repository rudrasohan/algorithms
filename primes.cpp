#include <bits/stdc++.h>
using namespace std;

bool prime(long N) {
    if (N == 1) return false; // 1 is a not prime
    if (N == 2) return true; // 2 is a prime
    if ((N & 0x1) == 0x0) return false; // All other evens never prime
    
    long rootN = (long) sqrt(N);
    
    for (long divisor = 3; divisor <= rootN; divisor += 2) {
        if ((N % divisor) == 0) return false;
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    bool b;
    cin >>n;
    long int a[n];
    for(int i = 0;i<n;i++)
        cin >>a[i];
    for(int i=0;i<n;i++)
    {
       b = prime(a[i]);
    //printf("Sohan");
    if(b == true)
        printf("Prime\n");
    else
        printf("Not prime\n");
    }
    return 0;
}
