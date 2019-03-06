#include "problem.h"


Problem::Problem(void(*prob)(), const std::string& annotation) :
	problem_(prob),
	problem_annotation_(annotation)
{}
