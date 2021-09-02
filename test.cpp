有问题，可以在页面上面留言

第一题Next方法移动节点是按照中序遍历移动吗？
是的

电梯的功能自己定义就行？、
基本功能上升，下降


1. 实现一个二叉搜索树的迭代器类
类的构造函数入参是二叉搜索树的根节点
类有一个Next方法支持移动迭代器并返回迭代器当前指向的节点

二叉搜索树节点定义如下
struct TreeNode {
		int value;
		struct TreeNode * left, * right;
};

class Iter {
public:
    void Inorder(TreeNode* root) {
        if (!root) return;
        Inorder(root->left);
        vec.push_back(root->val);
        Inorder(root->right);
    }

    Iter(TreeNode* root) {
        Inorder(root);
        start = 0;
    }
    int Next() {
        if (start >= vec.size()) return -1;
        return vec[start++];
    }
private:
    int start;
    vector<int> vec;
}

2. 一个长度为N的数列，可以任意移动数列中的数，请实现一个函数给出让数列变为升序的最少移动次数
示例，数列4,1,2,3,5,6,7,8 把4移动到3和5之间，算一次移动

int minExchange(vector<int>& nums) {
    int n = nums.size();
    vector<int> sortedNums(nums.begin(), nums.end());
    sort(sortedNums.begin(), sortedNums.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (sortedNums[i] != nums[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == sortedNums[i]) {
                    swap(nums[j], nums[i]);
                    res++;
                }
            }
        }
    }
    return res;
}

3. 给定两个单词（start和end）和一个字典，每次只能改变一个字母，变换过程中的单词必须在字典中出现，请给出从start到end的最短转换序列长度。
注意，如果没有转换序列则返回0，所有单词具有相同的长度，所有单词都只包含小写字母。
示例：start = "abc"，end = "xyz"，dict = ["aoc","xoc","xoz","not"]

int minDistance(string start, string end, vector<string>& dict) {
    queue<string> q;
    q.push(start);
    int res = 0;
    while (!q.empty()) {
        res++;
        for (int sz = q.size(); sz > 0; sz--) {
            string cur = q.front();
            if (cur == end) {
                return res;
            }
            q.pop();
            for (auto & w: dict) {
                //if (w.empty()) continue;
                int diff = 0;
                for (int i = 0; i < w.size(); i++) {
                    if (w[i] != cur[i]) ++diff;
                    if (diff > 1) break;
                }
                if (diff <= 1) {
                    q.push(w);
                    w = "";
                }
            }
        }
    }
    return 0;
}

4. 一个写字楼里面有多部电梯 请你设计一个类来实现电梯的功能 需要给出类的接口定义、关键的数据结构

class elevator {
public:
    elevator(int floors) {
    	_floors = floors;
    }
    void up(int n){
    	_target = n;
      run();
    }
    void down(int n){
    	_target = n;
      run();
    }
    void run() {

    }

private:
    int _floors;
    int _now;
    int _target;
}

