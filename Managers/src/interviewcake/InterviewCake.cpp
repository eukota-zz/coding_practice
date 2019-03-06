#include "InterviewCake.h"
#include "February2019.h"
#include "problem_group.h"
#include "tools.h"
#include <string>


int IC_PROBLEM_GROUP_IDX = 1;

void InterviewCake::InitGroups()
{
	ProblemGroup* feb2019 = new February2019();
	feb2019->InitProblemGroup();
	AddProblemGroup(feb2019);
}
