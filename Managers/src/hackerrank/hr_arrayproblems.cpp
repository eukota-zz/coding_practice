#include "hr_arrayproblems.h"
#include "HackerRank.h"
#include <iostream>


namespace {
	using namespace std;
}

HR_ArrayProblems::HR_ArrayProblems() :
	ProblemGroup(++HR_PROBLEM_GROUP_IDX, "String Problems")
{}

HR_ArrayProblems::~HR_ArrayProblems()
{}

void HR_ArrayProblems::InitProblemGroup()
{
	this->AddProblem(1, &arraySumOne, "Sum Arrays One");
}

void arraySumOne()
{
	long int N, K, p, q, sum, i, max = 0, x = 0;

	cin >> N >> K;
	long int *a = new long int[N + 1]();

	for (i = 0; i<K; i++)
	{
		cin >> p >> q >> sum;
		a[p] += sum;
		if ((q + 1) <= N)
			a[q + 1] -= sum;
	}

	for (i = 1; i <= N; i++)
	{
		x = x + a[i];
		if (max<x)
			max = x;

	}
	cout << max;
}