#pragma once
#include "problem_group.h"


class CTCI_Chapter1 : public ProblemGroup
{
public:
	CTCI_Chapter1();
	~CTCI_Chapter1();

	virtual void InitProblemGroup();
};

bool CTCI_isUnique(const std::string& str);
void CTCI_runIsUnique();
std::string CTCI_htmlEncode(const std::string& str);
void CTCI_runHtmlEncode();