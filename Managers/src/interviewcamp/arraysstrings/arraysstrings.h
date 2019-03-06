#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <utility>

// Dutch National Flag
void runSortArray();
void runZerosToEnd();
void runRedWhiteBlue();

// Reverse Traverse
void runCloneEvenNumbers();

// Subarray
void runSubarrayMaxSum();
void runSubarraySumX();
void runSubarrayCommonDiff();

// Traverse Both Ends
void runReverseArray();
void runFindSumNumbers();

template<class T>
void printVector(const std::vector<T>& v, bool lines = false, char div = ' ')
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << div;
		if (lines)
			cout << endl;
	}
}

template<class T>
void printVector(const std::vector<T>& v, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		cout << v[i] << ", ";
	}
}

template<class T>
void vectorSwap(std::vector<T>* v, size_t idx1, size_t idx2)
{
	// todo: bounds-check on idx1 and idx2
	T temp = (*v)[idx1];
	(*v)[idx1] = (*v)[idx2];
	(*v)[idx2] = temp;
}

