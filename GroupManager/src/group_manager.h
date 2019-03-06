#pragma once
#include <map>

// ProblemGroupBase
// Base class for ProblemGroup 
//
class ProblemGroup;
class GroupManager
{
public:
	GroupManager(const std::string& selectionString, const std::string& managerAnnotation, const std::string& managerIdentifier, const std::string& problemGroupIdentifier, const std::string& problemIdentifier);
	~GroupManager();
	void PrintMenu();
	void Run();
	
	std::string SelectionString() const { return selection_string_; }
	std::string ManagerAnnotation() const { return manager_annotation_; }

	std::string ManagerIdentifier() const { return manager_identifier_; }
	std::string ProblemGroupIdentifier() const { return group_identifier_; }
	std::string ProblemIdentifier() const { return problem_identifier_; }
	virtual void InitGroups() = 0;

protected:
	void AddProblemGroup(ProblemGroup* group, int groupNum = -1);
	std::map<int, ProblemGroup*> groups_;

private:
	const std::string selection_string_;
	const std::string manager_annotation_;
	const std::string manager_identifier_;
	const std::string group_identifier_;
	const std::string problem_identifier_;
	
	int next_group_num_;
};