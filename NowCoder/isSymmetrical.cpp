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
    bool isSymmetrical(TreeNode* pRoot) {
        return isSame(pRoot, pRoot);
    }
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return root1->val == root2->val &&
                isSame(root1->left, root2->right) &&
                isSame(root1->right, root2->left);
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        queue<TreeNode*> q1, q2;
        TreeNode *left, *right;
        q1.push(pRoot->left);
        q2.push(pRoot->right);
        while(!q1.empty() && !q2.empty()) {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (!left && !right) continue;
            if(!left || !right) return false;
            if (left->val != right->val) return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};