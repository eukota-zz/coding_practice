#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <tchar.h>

namespace
{
	using namespace std;
}

int _tmain(int argc, _TCHAR* argv[])
{

	ManagerManager* manager = new ManagerManager();

	GroupManager* sandboxManager = new Sandbox();
	sandboxManager->InitGroups();
	manager->AddGroupManager(sandboxManager);

	GroupManager* cakeManager = new InterviewCake();
	cakeManager->InitGroups();
	manager->AddGroupManager(cakeManager);

	GroupManager* ctciManager = new CTCI();
	ctciManager->InitGroups();
	manager->AddGroupManager(ctciManager);

	GroupManager* hrManager = new HackerRank();
	hrManager->InitGroups();
	manager->AddGroupManager(hrManager);

	GroupManager* tbManager = new Triplebyte();
	tbManager->InitGroups();
	manager->AddGroupManager(tbManager);

	GroupManager* campManager = new InterviewCamp();
	campManager->InitGroups();
	manager->AddGroupManager(campManager);

	bool runTests = false;
	string input;
	do
	{
		manager->PrintInstructions();
		cin >> input;
		manager->Run(input);
	} while (atoi(input.c_str()) != -1);

	return 0;
}

