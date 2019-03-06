#include <iostream>
#include <vector>
#include "arraysstrings.h"

namespace {
	using namespace std;
}

template<class T>
std::vector<T> reverseArray(vector<T>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		T x = v[v.size() - i - 1];
		v[v.size() - i - 1] = v[i];
		v[i] = x;
	}
	return v;
}

// given an array, reverse the order of its elements.
std::vector<int> reverseArray(vector<int>& v)
{
	for(size_t left=0; left<v.size()/2; left++)
	{
		size_t right = v.size()-left-1;
		int x = v[right];
		cout << "left : " << left << ", right: " << right << endl;
		v[right] = v[left];
		v[left] = x;
	}
	return v;
}
void runReverseArray()
{
	cout << "-----------------------------" << endl;
	cout << "Reverse Array" << endl;
	vector<int> v = { 3,5,2,5,2,3,9 };
	printVector(v);
	cout << endl;
	vector<int> r = reverseArray(v);
	printVector(r);
	cout << endl;
}


// find two numbers in array that sum to X
bool findSumNumbers(const vector<int>& v, int X, int* num1, int* num2)
{
	if(!num1 || !num2)
		return false;
	if(v.size() <= 1)
		return false;
	size_t left = 0;
	size_t right = v.size()-1;
	while(left != right)
	{
		int sum = v[left] + v[right];
		if(X < sum)
		{
			right--;
			continue;
		}
		else if(X > sum)
		{
			left++;
			continue;
		}
		else if(X == sum)
		{
			*num1 = v[left];
			*num2 = v[right];
			return true;
		}
	}
	return false;
}
void runFindSumNumbers()
{
	cout << "-----------------------------" << endl;
	cout << "Find Sum Numbers" << endl;
	vector<int> v2 = { 1,2,3,4,5,6,10 };
	int a, b = 0;
	bool numsExist = findSumNumbers(v2, 8, &a, &b);
	cout << (numsExist ? "Found: " : "Not found.") << endl;
	if (numsExist)
	{
		cout << "a: " << a << ", b: " << b << endl;
	}
}
