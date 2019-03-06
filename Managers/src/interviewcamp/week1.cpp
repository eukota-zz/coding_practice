#include "InterviewCamp.h"
#include "week1.h"
#include "problem_group.h"
#include "arraysstrings/arraysstrings.h"
#include <iostream>
#include <sstream>
#include <set>
#include <vector>


Week1::Week1() :
	ProblemGroup(++CAMP_PROBLEM_GROUP_IDX, "Interview Camp")
{}

Week1::~Week1()
{}

void Week1::InitProblemGroup()
{
	int idx = 0;
	AddProblem(++idx, &playgame, "Game");

	// Dutch National Flag
	AddProblem(++idx, &runSortArray, "runSortArray");
	AddProblem(++idx, &runZerosToEnd, "runZerosToEnd");
	AddProblem(++idx, &runRedWhiteBlue, "runRedWhiteBlue");

	// Reverse Traverse
	AddProblem(++idx, &runCloneEvenNumbers, "runCloneEvenNumbers");

	// Subarray
	AddProblem(++idx, &runSubarrayMaxSum, "runSubarrayMaxSum");
	AddProblem(++idx, &runSubarraySumX, "runSubarraySumX");
	AddProblem(++idx, &runSubarrayCommonDiff, "runSubarrayCommonDiff");

	// Traverse Both Ends
	AddProblem(++idx, &runReverseArray, "runReverseArray");
	AddProblem(++idx, &runFindSumNumbers, "runFindSumNumbers");
}

