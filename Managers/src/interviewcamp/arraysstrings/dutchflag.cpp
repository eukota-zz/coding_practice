#include <iostream>
#include <vector>
#include "arraysstrings.h"

namespace {
	using namespace std;
}

// dutch national flag problem
// sorts numbers into:
// < (*v)[idx]
// = (*v)[idx]
// > (*v)[idx]
void sortArray(vector<int>* v, size_t idx)
{
    if(!v)
        return;
    size_t low = -1;
    size_t mid = -1;
    size_t high = v->size();
    int splitVal = (*v)[idx];
    while(mid+1 < high)
    {
        int val = (*v)[mid+1];
        if(val > splitVal)
        {
            vectorSwap(v, mid+1, high-1);
            high = high - 1;
        }
        else if (val == splitVal)
        {
            mid = mid + 1;
        }
        else if (val < splitVal)
        {
            vectorSwap(v, mid+1, low+1);
            mid = mid + 1;
            low = low + 1;
        }
    }
}
void runSortArray()
{
	cout << "-----------------------------" << endl;
	cout << "Dutch Flag 1: Classic" << endl;
	vector<int> v = { 3,5,2,6,8,4,4,6,4,4,3 };
	printVector(v);
	cout << endl;
	sortArray(&v, 5);
	printVector(v);
	cout << endl;
}

void zerosToEnd(vector<int>* v, int pivot)
{
    if(!v)
        return;
    size_t low = -1;
    size_t high = v->size();
    while(low+1 < high)
    {
        int val = (*v)[low+1];
        if(val != pivot)
        {
            low = low + 1;
        }
        else if(val == pivot)
        {
            vectorSwap(v, low+1, high-1);
            high = high -1;
        }
    }
}
void runZerosToEnd()
{
	cout << "-----------------------------" << endl;
	cout << "Dutch Flag 2: Zeros to End" << endl;
	vector<int> v = { 2,3,0,3,0,1,0 };
	printVector(v);
	cout << endl;
	zerosToEnd(&v, 0);
	printVector(v);
	cout << endl;
}

// 0 red
// 1 white
// 2 blue
void RedWhiteBlue(vector<int>* v)
{
    if(!v)
        return;
    size_t low = -1;
    size_t mid = -1;
    size_t high = v->size();
    const int white = 1;
    while(mid+1 < high)
    {
        int val = (*v)[mid+1];
        if(val > white)
        {
            vectorSwap(v, mid+1, high-1);
            high = high - 1;
        }
        else if (val == white)
        {
            mid = mid + 1;
        }
        else if (val < white)
        {
            vectorSwap(v, mid+1, low+1);
            mid = mid + 1;
            low = low + 1;
        }
    }
}
void runRedWhiteBlue()
{
	cout << "-----------------------------" << endl;
	cout << "Dutch Flag 3: RedWhiteBlue" << endl;
	vector<int> v = { 1,0,1,2,1,0,1,2 };
	printVector(v);
	cout << endl;
	RedWhiteBlue(&v);
	printVector(v);
	cout << endl;
}
