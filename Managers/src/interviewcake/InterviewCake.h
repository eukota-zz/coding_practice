#pragma once
#include "group_manager.h"

extern int IC_PROBLEM_GROUP_IDX;

class GroupManager;
class InterviewCake : public GroupManager
{
public:
	InterviewCake() : GroupManager("i", "Iterview Cake", "Interview Cake", "Month and Year", "Problem") {}
	virtual void InitGroups();
};


