#include "InterviewCake.h"
#include "February2019.h"
#include "problem_group.h"
#include <iostream>
#include <set>
#include <vector>

February2019::February2019() :
	ProblemGroup(++IC_PROBLEM_GROUP_IDX, "February 2019")
{}

February2019::~February2019()
{}

void February2019::InitProblemGroup()
{
	this->AddProblem(1, &testGetMaxProfit, "Get Max Profit");
}


// February 2019
int getMaxProfit(vector<int>& stockPrices)
{
	size_t sellIndex = 0;
	size_t buyIndex = 1;
	bool possibleSale = false;
	for (size_t i = 2; i < stockPrices.size(); i++)
	{
		int saleVal = stockPrices[sellIndex] - stockPrices[buyIndex];
		possibleSale = (saleVal > 0);

		// iterate high if no possible anyway
		if (!possibleSale)
		{
			sellIndex++;
		}
		else if (stockPrices[i] > stockPrices[sellIndex])
		{
			sellIndex = i;
		}
		// iterate low if lower
		if (stockPrices[i] < stockPrices[buyIndex])
		{
			buyIndex = i;
		}
	}

	return stockPrices[sellIndex] - stockPrices[buyIndex];
}
void testGetMaxProfit()
{
	vector<int> stockPrices{ 10,7,5,8,11,9 };
	cout << "Max profit : " << getMaxProfit(stockPrices) << endl;
}
