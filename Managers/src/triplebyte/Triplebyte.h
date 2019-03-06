#pragma once
#include "group_manager.h"

extern int TB_PROBLEM_GROUP_IDX;

class GroupManager;
class Triplebyte : public GroupManager
{
public:
	Triplebyte() : GroupManager("t", "TB", "TB", "TicTacToe", "Game") {}
	virtual void InitGroups();
};
