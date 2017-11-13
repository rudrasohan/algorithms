#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void BFS(vector<vector<int> > pairs())
{/*
    list<int> queue;
    if(visited[s] == false)
    {
        cost += cl;
        visited[s] = true;
        queue.push_back(s);
    }
    
    list<int>::iterator i;

    while(!queue.empty())
    {

        s = queue.front();
        //cout << s << " ";
        queue.pop_front();
        for (i = pairs[s].begin(); i != pairs[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
            //cout <<"COST="<<cost<<endl;
        }
    }*/
}
int main()
{ 
    int N, I;

    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 0;
    
    /** Write code to compute the result using N,I,pairs **/
    int s = 0;
    bool *visited = new bool[N];
    for(int i = 0; i < n; i++)
        visited[i] = false;

     if(visited[s] == false)
    {
        visited[s] = true;
        queue.push_back(s);
    }
    
    list<int>::iterator i;

    while(!queue.empty())
    {

        s = queue.front();
        //cout << s << " ";
        queue.pop_front();
        for (i = pairs[s].begin(); i != pairs[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
            //cout <<"COST="<<cost<<endl;
        }

    
    cout << result << endl;
    return 0;
}
