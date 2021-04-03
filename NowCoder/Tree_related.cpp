/* 二叉树遍历框架 */
class TreeNode {
	int val;
	TreeNode left, right;
};

void traverse(TreeNode root) {
	// 前序遍历
	traverse(root.left);
	// 中序遍历
	traverse(root.right);
	// 后序遍历
}

// 前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
// 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
// 后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->left) st.push(p->left);
            if (p->right) st.push(p->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* N叉树遍历框架 */
class TreeNode {
	int val;
	TreeNode [] children;
};

void traverse(TreeNode root) {
	for (TreeNode child : root.children)
		traverse(child);
}

/* For example: LeetCode 124 求二叉树中最大路径和 */
class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        oneSideMax(root);
        return res;
    }
    int oneSideMax(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};

/* For example: LeetCode 105 根据前序遍历和中序遍历还原二叉树 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd)
            return NULL;
        int rootVal = preorder[preStart];
        int idx = -1;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == rootVal) {
                idx = i;
                break;
            }
        }
        int leftSize = idx - inStart;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, idx - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, idx + 1, inEnd);
        return root;
    }
};