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
    TreeNode* t1 = nullptr;  // 中序遍历，记录两个错误排序节点，最后进行交换
    TreeNode* t2 = nullptr;
    TreeNode* pre = nullptr;  // 记录中序遍历前一个节点
public:
    void recoverTree(TreeNode* root) {
        InOrder(root);
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }
    void InOrder(TreeNode* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        if (pre != nullptr && pre->val > root->val) {
            if (t1 == nullptr) t1 = pre;  // 记录第一个逆序节点
            t2 = root;  // 记录最后一个逆序节点
        }
        pre = root;
        InOrder(root->right);
    }
};