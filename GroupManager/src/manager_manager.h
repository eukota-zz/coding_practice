#pragma once
#include <map>

namespace
{
	using namespace std;
}

class GroupManager;
class ManagerManager
{
public:
	ManagerManager();
	~ManagerManager();

	void Run(const std::string& selectionString);
	void PrintInstructions();
	void AddGroupManager(GroupManager* manager);

private:
	map<std::string, GroupManager*> managers_;
};