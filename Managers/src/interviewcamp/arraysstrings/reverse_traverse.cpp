#include <iostream>
#include <vector>
#include "arraysstrings.h"

namespace {
	using namespace std;
}

vector<int> cloneEvenNumbers(vector<int> a, int lastNumber)
{
	int end = a.size();
	int i=lastNumber;
	while(i>=0)
	{
		if(a[i]%2==0)
		{
			a[--end] = a[i];
		}
		a[--end] = a[i];
		i--;
	}
	return a;
}
void runCloneEvenNumbers()
{
	vector<int> v = { 2,4,1,0,3,-1,-1,-1 };
	vector<int> r = cloneEvenNumbers(v, 4);
	for (size_t i = 0; i < r.size(); i++)
		cout << r[i] << endl;
}

