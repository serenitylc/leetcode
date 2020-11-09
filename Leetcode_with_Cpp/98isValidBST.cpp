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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) return true;
        if (min != NULL && min->val >= root->val) return false;
        if (max != NULL && max->val <= root->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};