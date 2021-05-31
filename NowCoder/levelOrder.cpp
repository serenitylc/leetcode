/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};