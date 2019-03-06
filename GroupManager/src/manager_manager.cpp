#include "manager_manager.h"
#include "group_manager.h"
#include <iostream>
#include <string>

ManagerManager::ManagerManager()
{
}

ManagerManager::~ManagerManager()
{
	for (map<std::string, GroupManager*>::iterator i = managers_.begin(), e = managers_.end(); i != e; i++)
		delete i->second;
}

void ManagerManager::AddGroupManager(GroupManager* manager)
{
	const std::string selStr = manager->SelectionString();
	map<std::string, GroupManager*>::iterator managerIt = managers_.find(selStr);
	if (managerIt != managers_.end())
	{
		cout << "WARNING: Selection String \"" << selStr << "\" already exists as a selection string.";
		return;
	}
	managers_[selStr] = manager;
}

void ManagerManager::PrintInstructions()
{
	cout << endl << "Main Menu:" << endl;
	for (map<std::string, GroupManager*>::iterator i = managers_.begin(), e = managers_.end(); i != e; i++)
	{
		cout << "// " << i->first << " --> " << i->second->ManagerAnnotation() << endl;
	}
	cout << endl;
}

void ManagerManager::Run(const std::string& selectionString)
{
	map<std::string, GroupManager*>::iterator managerIt = managers_.find(selectionString);
	if (managerIt == managers_.end())
	{
		cout << "WARNING: \"" << selectionString << "\" not found.";
		return;
	}
	managers_[selectionString]->Run();
}