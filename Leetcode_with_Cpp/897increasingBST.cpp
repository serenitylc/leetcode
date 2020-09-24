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
    TreeNode* head = new TreeNode(0);
    TreeNode* cur = head;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return NULL;
        increasingBST(root->left);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        increasingBST(root->right);
        return head->right;
    }
};

class Solution {
public:
    stack<TreeNode *> stk;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode *head = new TreeNode(0);
        TreeNode *cur = head;
        TreeNode *p = root;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                cur->right = new TreeNode(p->val);
                cur = cur->right;
                p = p->right;
            }
        }
        return head->right;
    }
};
