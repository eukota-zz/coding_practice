#pragma once
#include "group_manager.h"

extern int CTCI_PROBLEM_GROUP_IDX;

class GroupManager;
class CTCI : public GroupManager
{
public:
	CTCI() : GroupManager("c", "CTCI", "Cracking the Code Interview", "Chapter", "Problem") {}
	virtual void InitGroups();
};
