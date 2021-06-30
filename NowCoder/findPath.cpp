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
    void dfs(TreeNode* root, int exp, vector<int>& path, vector<vector<int> >& res) {
        path.push_back(root->val);
        if (root->val == exp && !root->left && !root->right) {
            res.push_back(path);
        }
        if (root->left) dfs(root->left, exp - root->val, path, res);
        if (root->right) dfs(root->right, exp - root->val, path, res);
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > res;
        vector<int> path;
        if (!root) return res;
        dfs(root, expectNumber, path, res);
        return res;
    }
};

// 查找二叉树根节点到任意结点的路径
class Solution {
public:
    unordered_map<int, TreeNode*> mp;  // 存储所有结点的父节点
    void dfs(TreeNode* root) {
        if (root->left) {
            mp[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            mp[root->right->val] = root;
            dfs(root->right);
        }
    }
    vector<int> findPath(TreeNode* root, TreeNode* target) {
        if (!root) return nullptr;
        mp[root->val] == nullptr;  // 根节点的父节点为 nullptr
        dfs(root);
        vector<int> res;
        while (target) {
            res.emplace_back(target->val);
            target = mp[target->val];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    // 递归查找根节点，返回true代表当前子树查找到，返回false代表当前子树没有查找到
    // s为传入参数，当函数调用结束时，s中存储target节点到根节点的路径，需要对s中的元素进行翻转
    bool findPath(TreeNode *root, stack<TreeNode*> & s, TreeNode *node) {
        if (!root) return false;
        s.push(root);
        if (root->val == node->val) return true;
        bool find = false;
        //先去查找左子树
        if (root->left) find = findPath(root->left, s, node);
        //当左子树没有查到时，去查找右子树
        if (!find && root->right) find = findPath(root->right, s, node);
        if (!find) s.pop();
        return find;
    }
    vector<int> findPath(TreeNode* root, TreeNode* target) {
        stack<TreeNode*> s;
        findPath(root, s, target);
        vector<int> res;
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            res.insert(res.begin(), cur->val);
        }
        return res;
    }
};