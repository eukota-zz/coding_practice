#pragma once
#include "problem_group.h"


class HR_StringProblems : public ProblemGroup
{
public:
	HR_StringProblems();
	~HR_StringProblems();

	virtual void InitProblemGroup();
};


bool isUnique(const std::string& str);
void runIsUnique();
