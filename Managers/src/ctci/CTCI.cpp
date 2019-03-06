#include "CTCI.h"
#include "CTCI_CH1.h"
#include "problem_group.h"
#include <iostream>

int CTCI_PROBLEM_GROUP_IDX = 0;

void CTCI::InitGroups()
{
	ProblemGroup* ch1 = new CTCI_Chapter1();
	ch1->InitProblemGroup();
	AddProblemGroup(ch1, 1);
}
