#pragma once
#include <string>
#include <map>
#include "problem.h"

namespace {
	using namespace std;
}

// ProblemGroup
//
// @param annotation - details about the problem group
class ProblemGroup
{
public:
	ProblemGroup(int problem_group_num_, const std::string& annotation);
	~ProblemGroup();
	void operator()(int problem);

	virtual void InitProblemGroup() = 0;

	void AddProblem(int problemNum, void(*prob)(), const std::string& annotation);
	const std::map<int, Problem*>* Problems() { return &problems_;  }
	std::string Annotation() { return problem_group_annotation_; }
	std::string FullAnnotation() const;
	std::string ProblemAnnotation(int problemNum) const;
	void PrintMenu(const std::string& entryPrefix) const;
private:
	std::map<int, Problem*> problems_;
	const std::string problem_group_annotation_;
	const int problem_group_num_;
};
