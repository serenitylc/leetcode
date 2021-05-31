 /**
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* root, int o1, int o2) {
        if (root == NULL || root->val == o1 || root->val == o2) return root;
        TreeNode *left = dfs(root->left, o1, o2);
        TreeNode *right = dfs(root->right, o1, o2);
        if (left && right) return root;
        return left ? left : right;

    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
       return dfs(root, o1, o2)->val;
    }
};
