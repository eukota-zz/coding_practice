#include "Sandbox.h"
#include "sand.h"
#include "problem_group.h"
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>


Sand::Sand() :
	ProblemGroup(++SAND_PROBLEM_GROUP_IDX, "Sandbox")
{}

Sand::~Sand()
{}

void Sand::InitProblemGroup()
{
	int idx = 0;
	AddProblem(++idx, &CipherTest, "Cipher");
	AddProblem(++idx, &IsPal, "Is Palindrome");
	AddProblem(++idx, &LongestPal, "Longest Palindrome");
	AddProblem(++idx, &ReverseInt, "Reverse Int");
	AddProblem(++idx, &IsPalindrome, "Is Palindrome");
	AddProblem(++idx, &IsMatch, "Wildcard Search");
	AddProblem(++idx, &Combinations, "Combinations");
	AddProblem(++idx, &SortInPlace, "SortInPlace");
	AddProblem(++idx, &triplets, "triplets");
	AddProblem(++idx, &boostTest, "boostTest");
	AddProblem(++idx, &runCopyTest, "runCopyTest");
}

void boostTest()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " ");
}

// Cipher 
void BuildCipher(std::map<char, char>& cipher, std::map<char, char>& decipher)
{
	// Upper Case Letters //
	for (int i = 65; i<91; i++)
	{
		int encode = 90 + 65 - i;
		cipher[i] = encode;
		decipher[encode] = i;
	}

	// Lower Case Letters //
	for (int i = 97; i<123; i++)
	{
		int encode = 122 + 97 - i;
		cipher[i] = encode;
		decipher[encode] = i;
	}

	return;
	// All ASCII Chars //
	for (int i = 0; i<128; i++)
	{
		int encode = 128 - i;
		cipher[i] = encode;
		decipher[encode] = i;
	}
}
void PrintCipher(const std::map<char, char>& cipher)
{
	const int MAX_SCREEN_WIDTH = 90;
	cout << "Cipher: " << endl;
	int charCount = 0;
	for (std::map<char, char>::const_iterator it = cipher.begin(), end = cipher.end(); it != end; ++it)
	{
		if (charCount + 10 > MAX_SCREEN_WIDTH)
			cout << endl;
		cout << "[" << it->first << " --> " << it->second << "] ";
	}
	cout << endl;
}
std::string EncodeString(const std::string& input, std::map<char, char>& cipher)
{
	std::ostringstream output;
	for (unsigned int i = 0; i<input.length(); i++)
		output << cipher[input[i]];

	std::string outputStr = string(output.str());
	return outputStr;
}
std::string DecodeString(const std::string& input, std::map<char, char>& decipher)
{
	std::ostringstream output;
	for (unsigned int i = 0; i<input.length(); i++)
		output << decipher[input[i]];

	std::string outputStr = string(output.str());
	return outputStr;
}
void RunCipher()
{
	std::map<char, char> cipher;
	std::map<char, char> decipher;

	std::string input;
	cout << "Cipher Selected." << endl;
	cout << "This function will run until you enter \"-1\" as a single input to encode." << endl;
	BuildCipher(cipher, decipher);
	PrintCipher(cipher);
	cout << endl;
	cout << "Enter what you would like to encode (no spaces): ";
	cin >> input;
	while (atoi(input.c_str()) != -1)
	{
		std::string input_en = EncodeString(input, cipher);
		cout << "Encoded: " << input_en << endl;
		cout << "Enter what you would like to encode (no spaces): ";
		cin >> input;
	}
}
void CipherTest()
{
	RunCipher();
	std::map<char, char> cipher;
	std::map<char, char> decipher;
	cout << "Running CipherTest" << endl;
	BuildCipher(cipher, decipher);
	PrintCipher(cipher);
	std::string a = "helloworld";
	std::string a_en = EncodeString(a, cipher);
	cout << "Encoded String: " << "\"" << a_en << "\"" << endl;
	std::string a_de = DecodeString(a_en, decipher);
	cout << "Decoded String: " << "\"" << a_de << "\"" << endl;
}

bool isPalindrome(const std::string& str, size_t start, size_t end)
{
	if (start == end)
		return true;

	const size_t size = str.size();
	for (size_t i = start, revIdx = end; i <= end && revIdx >= 0; ++i, --revIdx)
	{
		if (str[i] != str[revIdx])
			return false;
	}
	return true;
}
string longestPalindrome(string s)
{
	if (s.empty())
		return "";
	else if (s.size() == 1)
		return s;

	std::string longestPal = s.substr(0, 1);
	for (size_t i = 0; i<s.size(); ++i)
	{
		if (s.size() - i < longestPal.size())
			return longestPal;

		for (size_t j = i; j<s.size(); ++j)
		{
			const size_t strLen = j - i + 1;
			const size_t longestSize = longestPal.size();
			if (strLen < longestSize)
				continue;

			if (isPalindrome(s, i, j))
			{
				if (strLen > longestSize)
					longestPal = s.substr(i, strLen);
			}

		}
	}
	return longestPal;
}

void IsPal()
{
	std::string s;
	cout << "Enter string:";
	do
	{
		cin >> s;
		cout << isPalindrome(s, 0, s.size() - 1);
	} while (s != "Q");
}
void LongestPal()
{
	std::string s;
	cout << "Enter string:";
	do
	{
		cin >> s;
		cout << longestPalindrome(s);
		cout << endl;
	} while (s != "Q");
}

int reverseInt(int x)
{
	// check limit (-max overflows when positive...)
	if (x == std::numeric_limits<int>::min())
		return 0;

	bool isNegative = x<0;
	x = abs(x);
	string s = to_string(x);

	string rs = s; // copy same size
	for (size_t i = s.size() - 1, j = 0; i >= 0, j<s.size(); --i, ++j)
	{
		rs[j] = s[i];
	}

	return (isNegative ? -1 * x : x);
}
int reverseInt2(int x)
{
	int rev = 0;
	while (x > 0)
	{
		rev = rev * 10 + x % 10;
		x = x / 10;
	}
	return rev;
}
void ReverseInt()
{
	int i;
	do
	{
		cout << "Enter number to reverse:";
		cin >> i;
		cout << reverseInt(i) << endl;
	} while (i != -1);
	do
	{
		cout << "Enter number to reverse:";
		cin >> i;
		cout << reverseInt2(i) << endl;
	} while (i != -1);
}

bool isPalindrome(int x) {
	if (x<0 || (x != 0 && x % 10 == 0)) return false;
	int sum = 0;
	while (x>sum)
	{
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	return (x == sum) || (x == sum / 10);
}
void IsPalindrome()
{
	cout << "Check if number is a palindrome." << endl;
	int i;
	do
	{
		cout << "Enter number: ";
		cin >> i;
		cout << (isPalindrome(i) ? "true" : "false") << endl;
	} while (i != -1);
}

// fails - to fix, modify to iterate from end to start
bool isMatch(string s, string p)
{
	if (s.empty())
		return false;
	if (s == p)
		return true;

	size_t sIdx = 0;
	size_t sS = s.size();
	size_t pIdx = 0;
	size_t pS = p.size();
	for (; sIdx < sS && pIdx < pS; ++pIdx)
	{
		// character does not match
		if (s[sIdx] != p[pIdx] && p[pIdx] != '.')
		{
			// if next char is wildcard, continue
			if (pIdx + 1 < pS && p[pIdx + 1] == '*')
			{
				pIdx++;
				continue;
			}
			return false;
		}
		// if next char is wildcard
		if (pIdx + 1 < pS && p[pIdx + 1] == '*')
		{
			// move sIdx to end of set
			while (sIdx < sS && (s[sIdx] == p[pIdx] || p[pIdx] == '.'))
			{
				sIdx++;
				if (sIdx + 1 < sS && s[sIdx] == s[sIdx + 1])
					break;
			}
			pIdx++; // move past wildcard
			continue;
		}
		sIdx++;
	}
	return (sIdx == sS && pIdx == pS);
}

// solution from LeetCode uses DP
bool isMatch2(string s, string p) {
	int m = s.length(), n = p.length();
	vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			return dp[m][n];
}

void IsMatch()
{
	cout << "Wildcard comparison '.' for any letter and '*' for 0-N of preceding letter." << endl;
	string s;
	do
	{
		cout << "Enter string: ";
		cin >> s;
		string p;
		cout << "Enter pattern: ";
		cin >> p;
		cout << (isMatch(s, p) ? "true" : "false") << endl;
	} while (s != "-1");
}

void doCombinations(const vector<int>& v, size_t idx, vector<int>* s)
{
	for (size_t i = idx; i < v.size(); ++i)
	{
		s->push_back(v[i]);
		doCombinations(v, i + 1, s);
		s->pop_back();
	}
}

void Combinations()
{
	vector<int> v = { 1,2,3 };
	vector<int> s;
	doCombinations(v, 0, &s);
}


void printVector(const vector<int>& v)
{
	for (size_t i = 0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}
void swap(vector<int>& v, int a, int b)
{
	int t = v[a];
	v[a] = v[b];
	v[b] = t;
}

void sortInPlace(vector<int>& v, size_t start, size_t end)
{
	if (end <= start)
		return;
	size_t pivot = end;
	int pivotVal = v[pivot];
	size_t swapIdx = start;
	for (size_t runnerIdx = start; runnerIdx<end; ++runnerIdx)
	{
		if (v[runnerIdx] < pivotVal)
		{
			swap(v, swapIdx, runnerIdx);
			swapIdx++;
		}
	}
	swap(v, swapIdx, pivot);
	printVector(v);
	sortInPlace(v, start, swapIdx - 1); // sort left
	sortInPlace(v, swapIdx + 1, end); // sort right
}

void SortInPlace()
{
	vector<int> v = { 406, 157, 415, 318, 472, 46, 252, 187 ,364 ,481 ,450 ,90 ,390 ,35 ,452 ,74 ,196 ,312 ,142 ,160 ,143 ,220 ,483 ,392 ,443 ,488 ,79 ,234 ,68 ,150 ,356 ,496 ,69 ,88 ,177 ,12 ,288 ,120 ,222 ,270 ,441 ,422 ,103 ,321 ,65 ,316 ,448 ,331 ,117 ,183 ,184 ,128 ,323 ,141 ,467 ,31 ,172 ,48 ,95 ,359 ,239 ,209 ,398 ,99 ,440 ,171 ,86 ,233 ,293 ,162 ,121 ,61 ,317 ,52 ,54 ,273 ,30 ,226 ,421 ,64 ,204 ,444 ,418 ,275 ,263 ,108 ,10 ,149 ,497 ,20 ,97 ,136 ,139 ,200 ,266 ,238 ,493 ,22, 17, 39, };
	//vector<int> v = { 1, 3, 9, 8, 2, 7, 5 };
	sortInPlace(v, 0, v.size() - 1);
}

/////////////////////////////////////
// BROADPOINT GROUP SCREEN PROBLEM //
// Given an array which consists of non-negative integers and an integer m, 
// you can split the array into m non-empty continuous subarrays. 
// Write an algorithm to minimize the largest sum among these m subarrays.
// Note:
// If n is the length of array, assume the following constraints are satisfied :
// 1 <= n <= 1000
// 1 <= m <= min(50, n)
// please provide an explanation to your approach and unit tests.you may use any language.

/////////////////////////////////////

long countTriplets(vector<long> arr, long r) {
	if (arr.size() < 3)
		return 0;
	long count = 0;
	for (size_t i = 0; i<arr.size() - 2; i++)
	{
		long possibleCount = 0;
		int x = arr[i];
		if (x != 1 && x%r != 0)
			continue;
		size_t nextIt = i + 1;
		for (size_t i2 = nextIt; i2 < arr.size() - 2; i2++)
		{
			if (x == arr[i2])
			{
				nextIt++;
			}
		}
		for (size_t j = nextIt; j<arr.size() - 1; j++)
		{
			int y = arr[j];
			if (y != x*r)
				break;
			for (size_t j2 = j + 1; j2 < arr.size() - 1; j2++)
			{
				if (y == arr[j2])
				{
					possibleCount++;
					j++;
				}
				else
				{
					break;
				}
			}
			bool b = false;
			for (size_t k = j + 1; k<arr.size(); k++)
			{
				int z = arr[k];
				if (z != r*y)
				{
					b = true;
					break;
				}
				count += 1 + possibleCount;
			}
			if (b)
			{
				b = false;
				break;
			}
		}
	}
	return count;
}


void triplets()
{
	vector<long> v = { 1, 2, 2, 4 };
	long r = 2;
	cout << countTriplets(v, r) << endl;

	vector<long> v2 = { 1, 3, 9, 9, 27, 81 };
	long r2 = 3;
	cout << countTriplets(v2, r2) << endl;

	vector<long> v3 = { 1, 5, 5, 25, 125 };
	long r3 = 5;
	cout << countTriplets(v3, r3) << endl;

	vector<long> v100;
	for (int i = 0; i < 100; i++)
		v100.push_back(1);
	long r100 = 1;
	cout << countTriplets(v100, r100) << endl;
}


void runCopyTest()
{
	CopyTests* c = new CopyTests();
	for(int i=0; i<10; i++)
		c->AddNode(i);
	c->Print();
	cout << "-------------------" << endl;

	CopyTests copy(*c);
	delete c;
	copy.AddNode(55);
	copy.Print();
}

