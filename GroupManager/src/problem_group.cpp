#include "problem_group.h"
#include <iostream>
#include <sstream>


ProblemGroup::ProblemGroup(int problem_group_num, const std::string& annotation) :
	problem_group_num_(problem_group_num),
	problem_group_annotation_(annotation)
{}

ProblemGroup::~ProblemGroup()
{
	for (std::map<int, Problem*>::iterator i = problems_.begin(), e = problems_.end(); i != e; ++i)
		delete i->second;
}

// Locate problem function and run it
void ProblemGroup::operator()(int problem)
{
	if (problems_.find(problem) == problems_.end())
	{
		std::cout << "WARNING: " << problem_group_num_ << "." << problem << " not found" << endl;
		return;
	}
	problems_[problem]->operator()();
}

std::string ProblemGroup::FullAnnotation() const
{
	stringstream output;
	for (std::map<int, Problem*>::const_iterator g = problems_.begin(), h = problems_.end(); h != g; ++g)
	{
		output << g->first << ": " << g->second->Annotation().c_str() << endl;
	}
	return output.str();
}

std::string ProblemGroup::ProblemAnnotation(int problemNum) const
{
	std::map<int, Problem*>::const_iterator problem = problems_.find(problemNum);
	if (problem == problems_.end())
	{
		std::cout << "WARNING: " << problem_group_num_ << "." << problemNum << " not found" << endl;
		return std::string();
	}
	return problem->second->Annotation();
}

void ProblemGroup::PrintMenu(const std::string& entryPrefix) const
{
	for (std::map<int, Problem*>::const_iterator problem = problems_.begin(), end = problems_.end(); problem != end; problem++)
		cout << entryPrefix << "." << problem->first << " " << problem->second->Annotation() << endl;
}

void ProblemGroup::AddProblem(int problemNum, void(*prob)(), const std::string& annotation)
{
	std::map<int, Problem*>::iterator problemIt = problems_.find(problemNum);
	if (problemIt != problems_.end())
	{
		std::cout << "WARNING: " << problem_group_num_ << "." << problemNum << " already exists" << endl;
		return;
	}
	Problem* problem = new Problem(prob, annotation);
	problems_[problemNum] = problem;
}
