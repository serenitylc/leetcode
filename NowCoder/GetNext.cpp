/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = nullptr;
        TreeLinkNode* tmp = pNode;
        while (tmp) {
            root = tmp;
            tmp = tmp->next;
        }
        vector<TreeLinkNode*> v;
        pre_order(root, v);
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == pNode && i+1 != v.size())
                return v[i+1];
        }
        return nullptr;
    }
    void pre_order(TreeLinkNode* root, vector<TreeLinkNode*>& v) {
        if (!root) return;
        pre_order(root->left, v);
        v.push_back(root);
        pre_order(root->right, v);
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) return nullptr;
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        while (pNode->next) {
            TreeLinkNode* root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
};