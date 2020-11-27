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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getDepth(root);
        int n = pow(2, m) - 1;
        vector<vector<string>> res(m, vector<string>(n));
        bfs(res, root, 0, 0, n);
        return res;
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return 1 + max(left, right);
    }
    void bfs(vector<vector<string>>& res, TreeNode* root, int depth, int left, int right) {
        if (!root || left > right) return;
        int mid = left + (right - left) / 2;
        res[depth][mid] = to_string(root->val);
        bfs(res, root->left, depth + 1, left, mid - 1);
        bfs(res, root->right, depth + 1, mid + 1, right);
    }
};