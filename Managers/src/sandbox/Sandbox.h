#pragma once
#include "group_manager.h"

extern int SAND_PROBLEM_GROUP_IDX;

class GroupManager;
class Sandbox : public GroupManager
{
public:
	Sandbox() : GroupManager("s", "Sandbox", "Sandbox", "Sandbox", "Problem") {}
	virtual void InitGroups();
};
