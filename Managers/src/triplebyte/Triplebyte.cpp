#include "Triplebyte.h"
#include "tictactoe.h"
#include "problem_group.h"
#include "tools.h"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <set>

int TB_PROBLEM_GROUP_IDX = 0;

void Triplebyte::InitGroups()
{
	ProblemGroup* sand_problems = new TicTacToe();
	sand_problems->InitProblemGroup();
	AddProblemGroup(sand_problems);
}
