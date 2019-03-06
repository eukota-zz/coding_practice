#pragma once
#include <string>

// Problem Object
//
// @param function pointer to a void-return zero-input function to run
// @param annotation - description of the problem
class Problem
{
public:
	Problem(void(*prob)(), const std::string& annotation);
	virtual void operator()()
	{
		problem_();
	};

	std::string Annotation() { return problem_annotation_; }
private:
	std::string problem_annotation_;
	void(*problem_)();
};
