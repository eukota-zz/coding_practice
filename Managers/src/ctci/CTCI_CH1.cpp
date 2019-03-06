#include "CTCI.h"
#include "CTCI_CH1.h"
#include "problem_group.h"
#include <iostream>
#include <set>
#include <vector>
#include <sstream>

CTCI_Chapter1::CTCI_Chapter1() :
	ProblemGroup(++CTCI_PROBLEM_GROUP_IDX, "Chapter 1")
{}

CTCI_Chapter1::~CTCI_Chapter1()
{}

void CTCI_Chapter1::InitProblemGroup()
{
	AddProblem(1, &CTCI_runIsUnique, "Is String Unique");
	AddProblem(2, &CTCI_runHtmlEncode, "HTML Encode");
}


// 1.1 
bool CTCI_isUnique(const std::string& str)
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
void CTCI_runIsUnique()
{
	std::vector<std::string> strs = { "abc", "church" };
	for (size_t i = 0; i < strs.size(); ++i)
	{
		cout << "Checking if \"" << strs[i] << "\" contains all unique characters." << endl;
		cout << (CTCI_isUnique(strs[i]) ? "YES" : "NO") << endl;
	}

}

std::string CTCI_htmlEncode(const std::string& str)
{
	stringstream ss;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			ss << "%20";
		else
			ss << str[i];
	}
	return ss.str();
}
void CTCI_runHtmlEncode()
{
	cout << CTCI_htmlEncode("The quick brown fox jumped over the lazy yellow dog.");
}