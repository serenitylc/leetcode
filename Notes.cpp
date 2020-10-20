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


/*  */


/* BFS算法--最短距离 */


/* 二分查找 */


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
void insertSortBad(int *a, int n){
	int i, j;
	for (i = 1; i < n; ++i){
		for (j = i; a[j - 1] > a[j] && j > 0; --j){
			swap(a[j - 1], a[j]);
		}
	}
}
// 将频繁交换转换为赋值
void insertSort(int *a, int n){
	// 临时变量,存放需要移动的元素
	int temp = 0;
	int i, j;
	for (i = 1; i < n; ++i){
			temp = a[i];
			for (j = i; a[j - 1] > temp && j > 0; --j){
				a[j] = a[j - 1];
			}
		a[j] = temp;
	}
}

int main(){
	int a[7] = { 2, 1, 3, 4, 5, 9, 8 };
	insertSortBad(a, 7);
	for (int i = 0; i < 7; ++i)
		cout << a[i] << endl;

	system("pause");
	return 0;
}