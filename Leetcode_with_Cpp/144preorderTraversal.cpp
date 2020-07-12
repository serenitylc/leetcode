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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty())
        {
            if(p)
            {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else
            {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};



class Solution {
private:
    vector<int> res;
public:
    void preorder(TreeNode* root){
        if(root == nullptr) 
            return;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res; 
    }
};
