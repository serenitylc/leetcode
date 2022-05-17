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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool lr = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size, 0);
            for (int i = 0; i < size; ++i) {
                root = q.front();
                q.pop();
                level[lr ? i : size - i - 1] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(level);
            lr = !lr;
        }
        return res;
    }
};