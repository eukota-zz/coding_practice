#pragma once
#include "problem_group.h"
#include "tools.h"


class HR_TreeProblems : public ProblemGroup
{
public:
	HR_TreeProblems();
	~HR_TreeProblems();

	virtual void InitProblemGroup();
};


void topView(tools::TreeNode<int>* root);
void HR_TestTopView();