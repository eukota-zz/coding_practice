#pragma once
#include "group_manager.h"

extern int HR_PROBLEM_GROUP_IDX;

class GroupManager;
class HackerRank : public GroupManager
{
public:
	HackerRank() : GroupManager("h", "Hacker Rank", "Hacker Rank", "Type", "Problem") {}
	virtual void InitGroups();
};
