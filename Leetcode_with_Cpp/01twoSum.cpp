/*
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target && i != j) {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

int main() {
	Solution s;
	vector<int> res;

	int arr[4]={2, 7, 11, 15};
	vector<int> nums(arr, arr+4);

	res = s.twoSum(nums, 9);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
	system("pause");
	return 0;
}

*/

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++) {
			int another = target - nums[i];
			if (record.find(another) != record.end()) {
				int res[2] = {i, record[another]};
				return vector<int>(res, res+2);
			}
			record[nums[i]] = i;
		}
		// throw invalid_argument("the input has no solution");
		return {-1, -1};
	}
};

int main() {
	Solution s;
	vector<int> res;
	int arr[4]={2, 7, 11, 15};
	vector<int> nums(arr, arr+4);
	res = s.twoSum(nums, 9);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
	system("pause");
	return 0;
}