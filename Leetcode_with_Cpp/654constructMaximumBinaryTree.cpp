/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi)
            return NULL;
        if (lo == hi)
            return new TreeNode(nums[lo]);
        int rootIndex = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] > nums[rootIndex])
                rootIndex=i;
        }
        TreeNode* root = new TreeNode(nums[rootIndex]);
        root->left = build(nums, lo, rootIndex - 1);
        root->right = build(nums, rootIndex + 1, hi);
        return root;
    }
};