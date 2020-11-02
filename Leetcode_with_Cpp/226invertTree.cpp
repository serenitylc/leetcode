/**
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);     
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* head = q.front();
            q.pop();
            TreeNode* tmp = head->left;
            head->left = head->right;
            head->right = tmp;
            if(head->left != nullptr)
                q.push(head->left);
            if(head->right != nullptr)
                q.push(head->right);
        }
        return root;
    }
};