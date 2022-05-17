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
    int sumRootToLeaf(TreeNode* root) {
        return root ? _sumRootToLeaf(root, 0) : 0;
    }
    int _sumRootToLeaf(TreeNode* root, int num) {
        int sum = 0;
        num = (num << 1) + root->val;  // 从根节点到当前节点的值
        if (root->left == nullptr && root->right == nullptr) return num;
        if (root->left) sum += _sumRootToLeaf(root->left, num);
        if (root->right) sum += _sumRootToLeaf(root->right, num);
        return sum;
    }
};