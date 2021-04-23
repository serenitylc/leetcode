class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        if (abs(depth(pRoot->left) - depth(pRoot->right)) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int depth(TreeNode* root) {
        if (!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return 1 + max(l,r);
    }
};

class Solution {
public:
    map<TreeNode*, int> hs;
    int depth(TreeNode *root) {
        if (!root) return 0;
        if (hs.find(root) != hs.end()) return hs[root];
        int l = depth(root->left);
        int r = depth(root->right);
        return hs[root] = max(l, r) + 1;
    }
    bool judge(TreeNode *root) {
        if (!root) return true;
        return abs(hs[root->left] - hs[root->right]) <= 1 && judge(root->left) && judge(root->right);
    }
    bool IsBalanced_Solution(TreeNode* root) {
        depth(root);
        return judge(root);
    }
};