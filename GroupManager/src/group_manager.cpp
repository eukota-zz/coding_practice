#include "group_manager.h"
#include "problem_group.h"
#include "problem.h"
#include "tools.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

namespace {
	using namespace std;
}


GroupManager::GroupManager(const std::string& selectionString, const std::string& managerAnnotation, const std::string& managerIdentifier, const std::string& problemGroupIdentifier, const std::string& problemIdentifier) :
	selection_string_(selectionString),
	manager_annotation_(managerAnnotation),
	manager_identifier_(managerIdentifier),
	group_identifier_(problemGroupIdentifier),
	problem_identifier_(problemIdentifier),
	next_group_num_(1)
{
}

GroupManager::~GroupManager()
{
	for (std::map<int, ProblemGroup*>::iterator i = groups_.begin(), e = groups_.end(); i != e; ++i)
		delete i->second;
}

void GroupManager::PrintMenu()
{
	cout << "-------------------------------------------------------" << endl;
	cout << "Group: " << ManagerIdentifier().c_str() << endl;
	for (std::map<int, ProblemGroup*>::const_iterator i = groups_.begin(), e = groups_.end(); i != e; ++i)
	{
		i->second->PrintMenu(to_string(i->first));
	}
		//cout << i->first << "." << i->second->ProblemAnnotation(i->first).c_str() << endl;
	cout << endl;
}

void GroupManager::Run()
{
	cout << "Running new " << ManagerIdentifier().c_str() << " Tests" << endl;
	string input;
	do
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Enter " << ProblemGroupIdentifier().c_str() << "." << ProblemIdentifier().c_str() << " to run: " << endl;
		cout << "(enter \"?\" for list of functions)" << endl;

		cin >> input;
		if (input == "?")
		{
			PrintMenu();
			continue;
		}
		if (atoi(input.c_str()) == -1)
			return;

		std::vector<std::string> selection = (tools::split(input, "."));
		int problemgroup = atoi(selection[0].c_str());
		int problem = atoi(selection[1].c_str());
		cout << "-------------------------------------------------------" << endl;
		if (groups_.find(problemgroup) == groups_.end())
		{
			cout << "WARNING: " << ProblemGroupIdentifier() << " " << problemgroup << " not found." << endl;
			continue;
		}
		// eg: "Running Chapter 5, Problem 1: Insert Bits"
		cout << "Running " << ProblemGroupIdentifier() << " " << problemgroup << ", " << ProblemIdentifier() << " " << problem << ": " << groups_[problemgroup]->ProblemAnnotation(problem) << endl;
		groups_[problemgroup]->operator()(problem);

	} while (atoi(input.c_str()) != -1);
}

void GroupManager::AddProblemGroup(ProblemGroup* group, int groupNum)
{
	if (!group)
	{
		cout << "WARNING: GroupManager::AddProblemGroup called with no ProblemGroup" << endl;
		return;
	}

	if (groupNum == -1)
	{
		groupNum = next_group_num_;
		next_group_num_++;
	}

	std::map<int, ProblemGroup*>::iterator groupIt= groups_.find(groupNum);
	if (groupIt != groups_.end())
	{
		cout << "WARNING: " << ProblemGroupIdentifier() << " " << groupNum << " already exists." << endl;
		return;
	}
	groups_[groupNum] = group;
}