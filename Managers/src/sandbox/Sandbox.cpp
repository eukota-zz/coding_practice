#include "Sandbox.h"
#include "sand.h"
#include "problem_group.h"
#include "tools.h"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <set>

int SAND_PROBLEM_GROUP_IDX = 0;

void Sandbox::InitGroups()
{
	ProblemGroup* sand_problems = new Sand();
	sand_problems->InitProblemGroup();
	AddProblemGroup(sand_problems);
}
