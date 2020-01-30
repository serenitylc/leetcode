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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
            return false;
        if(p->val == q->val)
            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        return false;
    }
};