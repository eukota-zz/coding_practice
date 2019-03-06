#include "hr_treeproblems.h"
#include "HackerRank.h"
#include "tools.h"
#include <iostream>
#include <queue>
#include <list>


namespace {
	using namespace std;
}

HR_TreeProblems::HR_TreeProblems() :
	ProblemGroup(++HR_PROBLEM_GROUP_IDX, "String Problems")
{}

HR_TreeProblems::~HR_TreeProblems()
{}

void HR_TreeProblems::InitProblemGroup()
{
	this->AddProblem(1, &HR_TestTopView, "Tree Top View Print");
}

struct qstruct
{
	tools::TreeNode<int>* node;
	int level;
	qstruct(tools::TreeNode<int>* n, int l) : node(n), level(l)
	{}
};
// prints numbers looking straight down at the tree
// BFS is done using a queue
// left-most and right-most visited spots are tracked
// results are pushed on front (for left) and back (for right) of the list starting with the root node pushed on first
void topView(tools::TreeNode<int>* root)
{
	if (!root)
		return;

	std::list<int> results;
	results.push_back(root->data);
	int visitedLeft = 0;
	int visitedRight = 0;
	queue<qstruct> q;
	q.push(qstruct(root, 0));
	while (!q.empty())
	{
		qstruct entry = q.front();
		q.pop();
		if(entry.node->right)
			q.push(qstruct(entry.node->right, entry.level + 1));
		if (entry.node->left)
			q.push(qstruct(entry.node->left, entry.level - 1));

		if (entry.level < visitedLeft)
		{
			results.push_front(entry.node->data);
			visitedLeft--;
		}
		if (entry.level > visitedRight)
		{
			results.push_back(entry.node->data);
			visitedRight++;
		}
	}
	for (list<int>::iterator it = results.begin(), end = results.end(); it != end; ++it)
		cout << to_string(*it) << " ";
}
void HR_TestTopView()
{
	// build test tree
	tools::TreeNode<int>* n1 = new tools::TreeNode<int>(1);
	tools::TreeNode<int>* n2 = n1->AddRight(2);
	tools::TreeNode<int>* n3 = n2->AddRight(5);
	tools::TreeNode<int>* n4 = n3->AddRight(6);
	tools::TreeNode<int>* n5 = n3->AddLeft(3);
	tools::TreeNode<int>* n6 = n5->AddRight(4);
	tools::TreeNode<int>* n1L = n1->AddLeft(20);
	topView(n1);
}