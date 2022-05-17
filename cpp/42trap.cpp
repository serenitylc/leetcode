class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> left(n), right(n);  // left[i]表示i左边的最大值，right[i]表示i右边的最大值
		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], height[i + 1]);
		}
		int res = 0;
		for (int i = 1; i < n - 1; i++) {
			int level = min(left[i], right[i]);
			res += max(0, level - height[i]);
		}
		return res;
	}
};