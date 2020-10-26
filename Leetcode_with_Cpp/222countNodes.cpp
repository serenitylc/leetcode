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
    int countNodes(TreeNode* root) {
        /**
        完全二叉树的高度可以通过不断地访问左子树来获取
        判断左右子树的高度:
        如果相等, 说明左子树是满二叉树, 然后进一步判断右子树的节点数 (最后一层最后出现的节点必然在右子树中)
        如果不等, 说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数 (最后一层最后出现的节点必然在左子树中)
        **/
        if (root == NULL) return 0;
        int l_hight = getHight(root->left);
        int r_hight = getHight(root->right);
        if (l_hight == r_hight) 
            return (1 << l_hight) + countNodes(root->right);  // 1(根节点) + (1 << ld) - 1(左完全左子树节点数) + 右子树节点数量
        else return (1 << r_hight) + countNodes(root->left);  // 1(根节点) + (1 << rd) - 1(右完全右子树节点数) + 左子树节点数量
    }
    int getHight(TreeNode* node) {
        int high = 0;
        while (node) { high++; node = node->left; }
        return high;
    }
};