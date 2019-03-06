#include "HackerRank.h"
#include "hr_stringproblems.h"
#include "problem_group.h"
#include <iostream>
#include <set>
#include <vector>


HR_StringProblems::HR_StringProblems() :
	ProblemGroup(++HR_PROBLEM_GROUP_IDX, "String Problems")
{}

HR_StringProblems::~HR_StringProblems()
{}

void HR_StringProblems::InitProblemGroup()
{
	this->AddProblem(1, &runIsUnique, "Is String Unique");
}

// 1.1 
bool isUnique(const std::string& str)
{
	set<char> chars;
	for (size_t i = 0; i < str.size(); i++)
	{
		set<char>::iterator it = chars.find(str[i]);
		if (it != chars.end())
			return false;
		chars.insert(str[i]);
	}
	return true;
}
void runIsUnique()
{
	std::vector<std::string> strs = { "abc", "church" };
	for (size_t i = 0; i < strs.size(); ++i)
	{
		cout << "Checking if \"" << strs[i] << "\" contains all unique characters." << endl;
		cout << (isUnique(strs[i]) ? "YES" : "NO") << endl;
	}

}
