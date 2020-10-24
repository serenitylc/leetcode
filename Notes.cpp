/* C++常用数据结构 */
/* array */
#include <array>
array<int, 10> arr;
for (auto it = arr.begin(); it != arr.end(); it++)
	cout << *it << '\t';
arr.size();

/* queue */
#include <queue>
queue<int> que;
que.push(num);
que.empty();
que.size();
que.front();
que.back();
que.pop();

/* priority_queue */
q.push();
q.pop();
q.top();

/* stack */
#include <stack>
stack<int> st;
st.push(num);
st.empty();
st.size();
st.top();
st.pop();

/* list 双向链表 */
#include <list>
int nums[] = {1, 2, 3, 4, 5};
list<int> li(nums, nums + sizeof(nums) / sizeof(int));
auto it = li.begin();
li.insert(it, num);
li.assign();
li.front();
li.back();
li.pop_front();
li.pop_back();
li.push_front();
li.push_back();
li.size();
li.resize();
li.unique();
li.erase();
li.clear();
li.empty();

/* map */
#include <map>
map<char, int> m;
m['a'] = 1;
m.insert(pair<char, int>('b', 2));
m.erase('a');
auto it = m.find('b');
cout << it->first << it->second << endl;

/* unordered_map */
// find() 判断某键值是否存在, map.find(key) == map.end() 时不存在
// count() 统计key值在map中出现的次数

/* set */
#include <set>
int nums[] = {1, 2, 3, 4, 5};
set<int> s(nums, nums + sizeof(nums) / sizeof(int));
s.insert(6);
s.erase(2);
auto it = s.find(3);
cout << *it << endl;

/* unordered_set */
empty()
insert()
erase()

/* vector */
#include <vector>
vector<int> vec;
vec.push_back(num);
vec.pop_back();

/* bitset */
// bitset的大小在编译时就需要确定
// 定义bitset, bitset<16> b;
// b.size() 	 返回位数
// b.count() 	 返回1的个数
// b.any() 		 返回是否有1
// b.none() 	 返回是否没有1
// b.set() 		 全部变成1
// b.set(i) 	 将i+1位变成1
// b.set(i,x) 	 将i+1位变成x
// b.reset() 	 全部都变成0
// b.flip() 	 全部去翻
// b.to_string() 转为string类型


/* 二叉树遍历框架 */
class TreeNode {
	int val;
	TreeNode left, right;
}

void traverse (TreeNode root) {
	// 前序遍历
	traverse(root.left);
	// 中序遍历
	traverse(root.right);
	// 后序遍历
}


/* N叉树遍历框架 */
class TreeNode {
	int val;
	TreeNode [] children;
}

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


/* 动态规划：明确【状态】 --> 定义【dp数组/函数】的含义 --> 明确【选择】 --> 明确【base case】 */
/* 斐波那契数列之记忆化搜索 */
int fib(int N) {
	if (N < 1) return 0;
	vector<int> memo(N + 1, 0);
	return helper(memo, N);
}

int helper(vector<int>& memo, int n) {
	// base case
	if (n == 1 || n == 2) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
	return memo[n];
}

/* 斐波那契数列之dp数组迭代解法 */
int fib(int N) {
	vector<int> dp(N + 1, 0);
	// base case
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[N];
}

/* 凑零钱问题之带备忘录递归 */
def coinChange(coins: List[int], amount: int):
	memo = dict()
	def dp(n):
		if n in memo: return memo[n]
		if n == 0: return 0
		if n < 0: return -1
		res = float('INF')
		for coin in coins:
			subproblem = dp(n - coin)
			if subproblem == -1: continue
			res = min(res, 1 + subproblem)
		memo[n] = res if res != float('INF') else -1
		return memo[n]
	return dp(amount)

/* 凑零钱问题之dp数组迭代解法 */
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	// base case  dp[i] = x 当目标金额为i时，至少需要x枚硬币
	dp[0] = 0;
	for (int i = 0; i < dp.size(); i++) {
		for (int coin: coins) {
			// 子问题无解，跳过
			if (i - coin < 0) continue;
			dp[i] = min(dp[i], 1 + dp[i - coin]);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}


/* DFS回溯算法 */
result = []
def backtrack(路径, 选择列表):
	if 满足结束条件:
		result.add(路径)
		return
	for 选择 in 选择列表:
		做选择
		backtrack(路径, 选择列表)
		撤销选择

/* DFS回溯算法之全排列(输入一组不重复数字，返回他们的全排列) */
List<List<Integer>> res = new LinkedList<>();
List<List<Integer>> permute(int[] nums) {
	// 记录【路径】
	LinkedList<Integer> track = new LinkedList<>();
	backtrack(nums, track);
	return res;
}
void backtrack(int[] nums, LinkedList<Integer> track) {
	// 触发结束条件
	if (track.size() == nums.length) {
		res.add(new LinkedList(track));
		return;
	}
	for (int i = 0; i < nums.length; i++) {
		// 排除不合理的选择
		if (track.contains(nums[i]))
			continue;
		// 做选择
		track.add(nums[i]);
		// 进入下一层决策树
		backtrack(nums, track);
		track.removeLast();
	}
}

/* DFS回溯算法之N皇后问题 */
vector<vector<string>> res;
vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n, string(n, '.'));
	backtrack(board, 0);
	return res;
}
void backtrack(vector<string>& board, int row) {
	// 触发结束条件
	if (row == board.size()) {
		res.push_back(board);
		return;
	}
	int n = board[row].size();
	for (int col = 0; col < n; col++) {
		// 排除不合法选择
		if (!isValid(board, row, col))
			continue;
		// 做选择
		board[row][col] = 'Q';
		// 进入下一行决策
		backtrack(board, row + 1);
		// 撤销选择
		board[row][col] = '.';
	}
}
// 是否可以在 board[row][col] 放置皇后
bool isValid(vector<string>& board, int row, int col) {
	int n = board.size();
	// 检查列冲突
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	// 检查右上冲突
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q')
			return false;
	}
	// 检查左上冲突
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q')
			return false;
	}
	return true;
}


/* BFS算法(计算最短距离) */
int BFS(Node start, Node target) {
	queue<Node> q;		// 核心数据结构
	set<Node> visited;	// 避免回头路
	q.push(start);		// 起点入队
	visited.add(start);
	int step = 0;		// 记录扩散步数
	while (q not empty) {
		int sz = q.size();
		// 将当前队列中的所有节点向四周扩散
		for (int i = 0; i < sz; i++) {
			Node cur = q.pop();
			// 判断是否到达终点
			if (cur is target)
				return step;
			// cur相邻节点入队
			for (Node x : cur.adj())
				if (x not in visited) {
					q.push(x);
					visited.add(x);
				}
		}
		// 搜索完一层，更新步数
		step++;
	}
}

/* BFS算法之二叉树最小深度 */
int minDepth(TreeNode root) {
	if (root == NULL) return 0;
	queue<TreeNode> q = new LinkedList<>();
	q.push(root);
	int depth = 1;
	while (!q.isEmpty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			TreeNode cur = q.pop();
			if (cur.left == NULL && cur.right == NULL)
				return depth;
			if (cur.left)
				q.push(cur.left);
			if (cur.right)
				q.push(cur.right);
		}
		depth++;
	}
	return depth;
}

/* BFS算法之解开密码锁的最小次数 */


/* 基本二分查找 */
int binarySearch(int[] nums, int target) {
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}

/* 寻找左侧边界的二分查找I */
int left_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return left;
}

/* 寻找左侧边界的二分查找II */
int left_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	if (left >= nums.length || nums[left] != target)
		return -1;
	return left;
}

/* 寻找右侧边界的二分查找 */
int right_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	// 检查right越界
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}

/*  */


/*  */


/*  */


/*  */



/*
  插入排序，平均情况O(n^2)，最好O(n)，最坏O(n^2)，空间复杂度O(1)，稳定
  插入排序思想：
  a[5] = {2, 1, 3, 4, 5}
  外层循环： a[0]不用管，默认有序，从a[1]开始往后循环
  内层循环： 将需要移动的元素a[1]存入临时变量
			遍历a[1]前面的元素，与当前a[1]进行比较，若遍历的当前元素大于a[1]，元素后移a[j] = a[j - 1]
			直到数据元素小于等于临时变量
			移动完后，将当前位置赋值为临时变量
*/
#include <iostream>
using namespace std;

// 频繁交换
void insertSortBad(int *a, int n) {
	int i, j;
	for (i = 1; i < n; ++i) {
		for (j = i; a[j - 1] > a[j] && j > 0; --j)
			swap(a[j - 1], a[j]);
	}
}
// 将频繁交换转换为赋值
void insertSort(int *a, int n) {
	// 临时变量,存放需要移动的元素
	int temp = 0;
	int i, j;
	for (i = 1; i < n; ++i) {
		temp = a[i];
		for (j = i; a[j - 1] > temp && j > 0; --j)
			a[j] = a[j - 1];
		a[j] = temp;
	}
}

int main() {
	int a[7] = { 2, 1, 3, 4, 5, 9, 8 };
	insertSortBad(a, 7);
	for (int i = 0; i < 7; ++i)
		cout << a[i] << endl;

	system("pause");
	return 0;
}