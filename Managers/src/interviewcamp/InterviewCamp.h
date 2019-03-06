#pragma once
#include "group_manager.h"

extern int CAMP_PROBLEM_GROUP_IDX;

class GroupManager;
class InterviewCamp : public GroupManager
{
public:
	InterviewCamp() : GroupManager("a", "Interview Camp", "IC", "Week", "Problem") {}
	virtual void InitGroups();
};
