#pragma once
#include "problem_group.h"
#include <vector>
#include <iostream>

class Sand : public ProblemGroup
{
public:
	Sand();
	~Sand();

	virtual void InitProblemGroup();
};
void boostTest();
void BuildCipher(std::map<char, char>& cipher, std::map<char, char>& decipher);
void PrintCipher(const std::map<char, char>& cipher);
std::string EncodeString(const std::string& input, std::map<char, char>& cipher);
std::string DecodeString(const std::string& input, std::map<char, char>& decipher);
void RunCipher();
void CipherTest();

bool isPalindrome(const std::string& str, size_t start, size_t end);
string longestPalindrome(string s);
void IsPal();
void LongestPal();
int reverseInt(int x);
int reverseInt2(int x);
void ReverseInt();
bool isPalindrome(int x);
void IsPalindrome();

bool isMatch(string s, string p);
bool isMatch2(string s, string p);
void IsMatch();

void doCombinations(const vector<int>& v, size_t idx, vector<int>* s);
void Combinations();
void printVector(const vector<int>& v);
void swap(vector<int>& v, int a, int b);

void sortInPlace(vector<int>& v, size_t start, size_t end);
void SortInPlace();

long countTriplets(vector<long> arr, long r);
void triplets();

void runCopyTest();

struct CopyNode
{
	CopyNode(int X) : x(X) {}
	CopyNode& operator=(const CopyNode& rhs)
	{
		x = rhs.x;
	}
	int x;
};

class CopyTests
{
public:
	CopyTests() {}
	CopyTests(const CopyTests& rhs)
	{
		for (vector<CopyNode*>::const_iterator it=rhs.nodes.begin(), end=rhs.nodes.end(); it!=end; ++it)
		{
			CopyNode* n = new CopyNode((*it)->x);
			nodes.push_back(n);
		}
	}
	~CopyTests() {}

	void AddNode(int x)
	{
		nodes.push_back(new CopyNode(x));
	}

	void Print()
	{
		for (size_t i = 0; i < nodes.size(); i++)
			cout << nodes[i]->x << ", ";
	}
private:
	vector<CopyNode*> nodes;
};