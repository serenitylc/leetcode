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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        // 根节点的左或右子树为空是构不成子树的, 即null节点不参与比较。
        if(!root->left && root->right)
            return 1 + minDepth(root->right);
        if(root->left && !root->right)
            return 1 + minDepth(root->left);

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        return min(leftDepth, rightDepth) + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right)
                    return depth;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};