#include "tools.h"
#include <vector>
#include <bitset>
#include <iostream>

namespace
{
	using namespace std;
}

namespace tools
{

	const size_t BITSET_SIZE = 10;
	void printBinary(int val)
	{
		cout << bitset<BITSET_SIZE>(val);
	}

	std::vector<std::string> split(const std::string& str, const char* delim)
	{
		std::vector<std::string> v;
		if (str.empty())
			return v;

		size_t begin = 0;
		for (size_t i = 0; i <= str.size(); i++)
		{
			if (str[i] != *delim && i != str.size())
				continue;

			v.push_back(str.substr(begin, i - begin));
			begin = i + 1;
		}
		return v;
	}

	void printSpace(int num)
	{
		for (int i = 0; i<num; ++i)
			cout << " ";
	}

	string spaces(int num)
	{
		string s;
		for (int i = 0; i<num; ++i)
			s += " ";
		return s;
	}


}
