#pragma once
#include "problem_group.h"
#include <vector>


class February2019 : public ProblemGroup
{
public:
	February2019();
	~February2019();

	virtual void InitProblemGroup();
};


int getMaxProfit(vector<int>& stockPrices);
void testGetMaxProfit();