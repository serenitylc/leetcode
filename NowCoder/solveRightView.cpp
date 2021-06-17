class Solution {
public:
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        vector<int> res;
        if (xianxu.empty()) return res;
        TreeNode* tree = helper(xianxu, 0, xianxu.size() - 1, zhongxu, 0, zhongxu.size() - 1);
        list<TreeNode*> l;
        l.push_back(tree);
        int count = 1;
        while (!l.empty()) {
            for (int i = 1; i <= count; ++i) {
                if (l.front()->left) l.push_back(l.front()->left);
                if (l.front()->right) l.push_back(l.front()->right);
                if (i == count) res.push_back(l.front()->val);
                l.pop_front();
            }
            count = l.size();
        }
        return res;
    }
    TreeNode* helper(vector<int> &pre, int p_l, int p_r, vector<int> &vin, int v_l, int v_r) {
        TreeNode* res = new TreeNode(pre[p_l]);
        int father = v_l - 1;
        while (pre[p_l] != vin[++father]);
        if (father > v_l) res->left = helper(pre, p_l + 1, p_l + father - v_l, vin, v_l, father - 1);
        if (father < v_r) res->right = helper(pre, p_l + father - v_l + 1, p_r, vin, father + 1, v_r);
        return res;
    }
};