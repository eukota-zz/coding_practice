#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <utility>
#include "arraysstrings.h"

namespace{
	using namespace std;
}

int subarrayMaxSum(vector<int>& v)
{
    // find max sum
    int maxSum = 0;
    size_t maxSumIdx = -1;
    int prev = 0;
    for(size_t i=0; i<v.size(); i++)
    {
        v[i] = max<int>(0, prev+v[i]);
        prev = v[i];
        maxSum = max<int>(maxSum,v[i]);
        if(maxSum == v[i])
            maxSumIdx = i;
    }
    stack<int> subset;
    // find where max sum came from
    int sum = 0;
    int leftIdx = maxSumIdx;
    while(leftIdx > 0)
    {
        sum += v[leftIdx] - v[leftIdx-1];
        if(sum == maxSum)
            break;
        subset.push(v[leftIdx] - v[leftIdx-1]);
        leftIdx--;
    }
    subset.push(v[leftIdx] - v[leftIdx-1]);
    cout << "Subarray: ";
    while(!subset.empty())
    {
        cout << subset.top() << ",";
        subset.pop();
    }
    cout << endl;
    return maxSum;
}
void runSubarrayMaxSum()
{
	cout << "-----------------------------" << endl;
	cout << "Subarray: Max Sum" << endl;
	vector<int> v = { -2,-3,4,-1,-2,1,5,-1 };
	printVector(v);
	cout << endl;
	int maxSum = subarrayMaxSum(v);
	cout << "Max Sum: " << maxSum;
	cout << endl;
}

vector<int> subarraySumX(vector<int>& v, int target)
{
    int start = -1;
    int end = -1;
    int sum = 0;
    int s = v.size();
    vector<int> res = { -1, -1 };
    while(start < s)
    {
        //cout << "s: " << start << ", e: " << end << endl;
        if(sum < target)
        {
            if(start == -1)
                start++;
            end++;
            if(end >= (int)v.size())
                break;
            sum += v[end];
        }
        else if(sum > target && start < end)
        {
            if(start >= (int)v.size())
                break;
            sum -= v[start];
            start++;
        }
        else
        {
            res[0] = start;
            res[1] = end;
            break;
        }
    }
    return res;
}
void runSubarraySumX()
{
	cout << "-----------------------------" << endl;
	cout << "Subarray: Find Target Sum" << endl;
	vector<int> v = { 2,1,4,5,3,5,1,2,4 };
	printVector(v);
	cout << endl;
	vector<int> r = subarraySumX(v, 12);
	cout << "Indices: " << r[0] << ", " << r[1];
	cout << endl;
	cout << "Subarray summing to 12: ";
	printVector<int>(v, r[0], r[1]);
	cout << endl;
}

pair<int,int> subarrayCommonDiff(vector<int>& v, int target)
{
    vector<int> cumsum = v;
    map<int,int> cache;
    int sum = 0;
    for(int i=0; i<(int)v.size(); i++)
    {
        sum += v[i];
        if(sum==target)
            return pair<int,int>(target,i);
        if(cache.find(sum) != cache.end())
        {
            cout << "cache " << cache.find(sum)->second+1 << endl;
            return pair<int,int>(cache.find(sum)->second+1, i);
        }
        
        cache[sum] = i;
    }
	return pair<int, int>(-1, -1);
}
void runSubarrayCommonDiff()
{
	cout << "-----------------------------" << endl;
	cout << "Subarray: \"Common Diff\" Find Target Sum With Negatives" << endl;
	vector<int> v = { -1,-1,2,1,-4,2,3,-1,2 };
	printVector(v);
	cout << endl;
	int target = 5;
	pair<int, int> r = subarrayCommonDiff(v, target);
	cout << "Indices: " << r.first << ", " << r.second;
	cout << endl;
	cout << "Subarray summing to " << target << ": ";
	printVector<int>(v, r.first, r.second);
	cout << endl;
}

