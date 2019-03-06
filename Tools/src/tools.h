#pragma once
#include <string>
#include <sstream>
#include <vector>
namespace
{
	using namespace std;
}

namespace tools
{
	std::vector<std::string> split(const std::string& str, const char* delim);

	void printBinary(int val);

	template<typename T>
	void printVector(const std::vector<T>& v)
	{
		cout << "[";
		for (std::vector<T>::const_iterator i = v.begin(), e = v.end(); i != e; ++i)
		{
			cout << *i;
			if (i + 1 != e)
				cout << ",";
		}

		cout << "]" << endl;
	};

	void printSpace(int num);
	string spaces(int num);

	template<typename T>
	class TreeNode {
	public:
		T data;
		TreeNode(T input) : right(NULL), left(NULL)
		{
			data = input;
		}
		~TreeNode()
		{
			delete right;
			delete left;
		}
		TreeNode<T>* right;
		TreeNode<T>* left;

		TreeNode<T>* AddRight(T data)
		{
			if (right)
				return NULL;
			TreeNode<T>* newNode = new TreeNode<T>(data);
			right = newNode;
			return right;
		}
		TreeNode<T>* AddLeft(T data)
		{
			if (left)
				return NULL;
			TreeNode<T>* newNode = new TreeNode<T>(data);
			left = newNode;
			return left;
		}
	};
}
