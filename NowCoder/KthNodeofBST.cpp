/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    unordered_map<TreeNode*, int> mp;
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (!pRoot || k < 0) return nullptr;
        int numOfLeft = dfs(pRoot->left);
        if (numOfLeft + 1 == k) return pRoot;
        else if (numOfLeft + 1 < k) return KthNode(pRoot->right, k - numOfLeft - 1);
        else return KthNode(pRoot->left, k);
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (mp.find(root) != mp.end()) return mp[root];
        mp[root] = 1 + dfs(root->left) + dfs(root->right);
        return mp[root];
    }
};