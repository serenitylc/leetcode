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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

class Solution {
public:
    unordered_map<int, TreeNode*> ump;
    void dfs(TreeNode* root) {
        if (root->left) {
            ump[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            ump[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val == p->val || root->val == q->val) return root;
        ump[root->val] == nullptr;
        dfs(root);
        vector<TreeNode*> toP;
        vector<TreeNode*> toQ;
        toP.push_back(p);
        toQ.push_back(q);
        while (p != nullptr) {
            toP.push_back(ump[p->val]);
            p = ump[p->val];
        }
        while (q != nullptr) {
            toQ.push_back(ump[q->val]);
            q = ump[q->val];
        }
        reverse(toP.begin(), toP.end());
        reverse(toQ.begin(), toQ.end());
        int i = 1;
        int sp = toP.size();
        int sq = toQ.size();
        bool flag = false;
        if (sp > sq) flag = true;
        int same = flag ? sq : sp;
        while (i < same && toP[i]->val == toQ[i]->val) i++;
        return toP[i-1];
    }
};