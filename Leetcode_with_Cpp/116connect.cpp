/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        connectTwoNode(root->left, root->right);
        return root;
    }
    void connectTwoNode(Node* node1, Node* node2) {
        if (node1 == NULL || node2 == NULL)
            return;
        node1->next = node2;
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);
        connectTwoNode(node1->right, node2->left);
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};