class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
		int l = 0, r = nums.size() - 1;
		while(l < r) {  //找到起始位置 
			int mid = l+r >> 1;
			if(nums[mid] >= target)
                r = mid;
			else l = mid + 1;
		}
		if (nums[l] != target) 
            return {-1,-1};
		int start = l;
		r = nums.size() - 1;
		while(l < r) {  //找到终点位置
			int mid = l+r+1 >> 1;  // 不加括号效率更高
			if (nums[mid] > target)
                r = mid - 1;
			else l = mid;
		}
		return {start,r};
    }
};