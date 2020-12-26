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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> path;
        TreeNode* cur = root;
        while (cur || !path.empty()) {
            while (cur) {
                path.push(cur);
                cur = cur->left;
            }
            if (!path.empty()) {
                cur = path.top();
                path.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};