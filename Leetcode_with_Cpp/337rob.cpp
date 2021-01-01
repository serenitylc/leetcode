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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo[root])
            return memo[root];
        int do_it = root->val + (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right)) + 
                                (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));
        int not_do = rob(root->left) + rob(root->right);
        int res = max(do_it, not_do);
        memo[root] = res;
        return res;
    }
};