/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return pRootOfTree;
        TreeNode* p = pRootOfTree;
        while (p && p->left) p = p->left;
        inOrder(pRootOfTree);
        return p;
    }
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        root->left = pre;  // 更新当前节点的left指向链表上一个节点
        if (pre) pre->right = root;  // 更新链表上一个节点的right指向当前节点
        pre = root;
        inOrder(root->right);
    }
};