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
    char* Serialize(TreeNode *root) {
        if (!root) return "#";
        string str = to_string(root->val);
        str.push_back('!');
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* res = new char[strlen(left) + strlen(right) + str.size()];
        strcpy(res, str.c_str());
        strcat(res, left);
        strcat(res, right);
        return res;
    }
    TreeNode* Deserialize(char *str) {
        return deserialize(str);
    }
    TreeNode* deserialize(char* & s) {
        if (*s == '#') {
            ++s;
            return nullptr;
        }
        int num = 0;
        while (*s != '!') {
            num = num * 10 + (*s - '0');
            ++s;
        }
        ++s;
        TreeNode* root = new TreeNode(num);
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
};