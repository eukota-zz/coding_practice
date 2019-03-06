#include "InterviewCamp.h"
#include "week1.h"
#include "problem_group.h"
#include "tools.h"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <set>

int CAMP_PROBLEM_GROUP_IDX = 0;

void InterviewCamp::InitGroups()
{
	ProblemGroup* w1_problems = new Week1();
	w1_problems->InitProblemGroup();
	AddProblemGroup(w1_problems);
}
