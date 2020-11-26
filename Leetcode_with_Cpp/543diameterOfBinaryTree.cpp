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
private:
    int res = 0;  // 最长直径不一定过根节点, 所以需要遍历每个节点, 以每个节点为中心点计算最长路径 (左子树边长+右子树边长)
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        oneSideMax(root);
        return res;

    }
    int oneSideMax(TreeNode* root) {
        if (!root->left && !root->right) return 0;
        int leftSize = root->left ? 1 + oneSideMax(root->left) : 0;
        int rightSize = root->right ? 1 + oneSideMax(root->right) : 0;
        res = max(res, leftSize + rightSize);
        return max(leftSize, rightSize);
    }
};