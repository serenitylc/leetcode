int* twoSum(int* nums, int numsSize, int target)
{
    static int a[2]={0};
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i+1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}
	return 0;
}

/*

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> record;
		for(int i = 0; i < nums.size(); i++) {
			int another = target - nums[i];
			if(record.find(another) != record.end()) {
				int res[2] = {i, record[another]};
				return vector<int>(res, res+2);
			}
			record[nums[i]] = i;
		}
		// throw invalid_argument("the input has no solution");
		return {-1, -1};
	}
};

*/