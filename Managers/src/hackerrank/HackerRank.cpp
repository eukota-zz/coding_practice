#include "HackerRank.h"
#include "hr_stringproblems.h"
#include "hr_arrayproblems.h"
#include "hr_treeproblems.h"
#include "problem_group.h"
#include <iostream>

int HR_PROBLEM_GROUP_IDX = 0;

void HackerRank::InitGroups()
{
	ProblemGroup* string_problems = new HR_StringProblems();
	string_problems->InitProblemGroup();
	AddProblemGroup(string_problems);

	ProblemGroup* array_problems = new HR_ArrayProblems();
	array_problems->InitProblemGroup();
	AddProblemGroup(array_problems);

	ProblemGroup* tree_problems = new HR_TreeProblems();
	tree_problems->InitProblemGroup();
	AddProblemGroup(tree_problems);
}

