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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        bool flag = true;
        while (!q.empty()) {
            vector<int> path;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* tmp = q.front();
                path.push_back(tmp->val);
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            if (!flag) reverse(path.begin(), path.end());
            res.push_back(path);
            flag = !flag;
        }
        return res;
    }

};