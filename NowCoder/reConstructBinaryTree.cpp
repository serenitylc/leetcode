/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    TreeNode* reConstructBinaryTree(vector<int>& pre, int pStart, int pEnd, \
                                    vector<int>& vin, int vStart, int vEnd) {
        if (pStart > pEnd) return NULL;
        int pos = -1;
        int numRoot = pre[pStart];
        for (int i = vStart; i <= vEnd; ++i) {
            if (vin[i] == numRoot) {
                pos = i;
                break;
            }
        }
        int leftsize = pos - vStart;
        TreeNode* root = new TreeNode(numRoot);
        root->left = reConstructBinaryTree(pre, pStart + 1, pStart + leftsize, vin, vStart, pos - 1);
        root->right = reConstructBinaryTree(pre, pStart + leftsize + 1, pEnd, vin, pos + 1, vEnd);
        return root;
    }
};