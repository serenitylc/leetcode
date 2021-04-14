/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;
        TreeNode* tmp = pRoot->left;
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = Mirror(tmp);
        return pRoot;
    }
};

class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return pRoot;
    }
};