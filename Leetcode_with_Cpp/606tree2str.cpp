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
    string tree2str(TreeNode* t) {
        string res = "";
        if (t == NULL) return res;
        res.append(to_string(t->val));
        if (t->left == NULL && t->right == NULL) return res;
        res += ("(" + tree2str(t->left) + ")");
        if (t->right) res += ("(" + tree2str(t->right) + ")");
        return res;
    }
};