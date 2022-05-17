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
private:
    int res = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        oneSideMax(root);  // 最长路径 (路径中每个节点具有相同值)
        return res;
    }
    int oneSideMax(TreeNode* root) {
        if (!root->left && !root->right) return 0;
        int leftSize = root->left ? 1 + oneSideMax(root->left) : 0;
        int rightSize = root->right ? 1 + oneSideMax(root->right) : 0;
        if (leftSize > 0 && root->val != root->left->val)
            leftSize = 0;  // 如果根节点和左孩子节点不同值，就把边长重新赋值为0
        if (rightSize > 0 && root->val != root->right->val)
            rightSize = 0;
        res = max(res, leftSize + rightSize);
        return max(leftSize, rightSize);
    }
};