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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        oneSideMax(root, res);
        return res;
    }
    int oneSideMax(TreeNode* root, int & res) {
        if (!root) return 0;
        int l = max(0, oneSideMax(root->left, res));
        int r = max(0, oneSideMax(root->right, res));
        res = max(res, l + r + root->val);
        return max(l, r) + root->val;
    }
};