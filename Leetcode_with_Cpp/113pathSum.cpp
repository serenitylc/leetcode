/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, res, path, targetSum);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int targetSum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == targetSum) {
            res.push_back(path);
            //return;
        }
        dfs(root->left, res, path, targetSum - root->val);
        dfs(root->right, res, path, targetSum - root->val);
        path.pop_back();
    }
};