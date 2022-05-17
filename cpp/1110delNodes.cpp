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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        // 根节点的父节点默认需要删除
        dfs(del, root, 1);
        return res;
    }
    // 使用flag标记当前节点的父节点是否需要删除
    void dfs(unordered_set<int>& del, TreeNode*& root, int flag) {
        if (!root) return;
        int found = del.count(root->val);
        dfs(del, root->left, found);
        dfs(del, root->right, found);
        // 父节点在需要删除的时候才加入结果
        if (!found && flag) res.push_back(root);
        if (found) root = nullptr;
    }
};