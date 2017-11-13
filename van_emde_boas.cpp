#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

#define root(x) (int)sqrt(x)

int n;
int *T;
bool *Summary;
int *maxT;
int *minT;
/*
int Successor()
{

}

void Insert()
{

}
void Delete()
{

}*/

int main()
{
	cout <<"Enter size\n";
	cin >>n;
	T = new int(n);
	Summary = new bool(root(n));
	maxT = new int(root(n));
	minT = new int(root(n));
	return 0;

}