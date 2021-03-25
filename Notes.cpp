
/* sort(v.begin(), v,end(), compare);
 * bool compare(int a, int b) { return a < b; }  升序排列(默认)
 * #include <functional>
 * 升序: sort(begin, end, less<data-type>())
 * 降序: sort(begin, end, greater<data-type>())
 */

/* #include <numeric>
 * accumulate(v.begin(), v.end(), 0);  累加起始值
 * partial_sum(first, last, dest);  部分和
 */

/* C++ string
 * #include <string>
 * string str;							生成空字符串
 * string s(str);						生成字符串为str的复制
 * string s(str, str_begin, str_len);	将字符串str中从下标str_begin开始、长度为str_len的部分作为字符串初值
 * string s(cstr, char_len);			以C_string类型cstr的前char_len个字符串作为字符串s的初值
 * string s(num, char);					生成num个c字符的字符串
 * string s(str, str_index);			将字符串str中从下标str_index开始到字符串结束的位置作为字符串初值
 *
 * size()、 length(): 	返回string对象的字符个数, 执行效果相同
 * max_size(): 			返回string对象最多包含的字符数，超出会抛出length_error异常
 * capacity()：			重新分配内存之前，string对象能包含的最大字符数
 *
 * string的插入：push_back()、 insert()
 * s.push_back('a');
 * s.insert(s.begin(), '1');
 *
 * string拼接字符串：append() 、 +
 *
 * string的遍历：借助迭代器 或者 下标法
 * 正向迭代器 str.begin()、  str.end()
 * 反向迭代器 str.rbegin()、 str.rend()
 *
 * string的删除：erase()
 * iterator erase(iterator p);						删除字符串中p所指的字符
 * iterator erase(iterator first, iterator last);	删除字符串中迭代器区间 [first, last) 上所有字符
 * string& erase(size_t pos, size_t len);			删除字符串中从索引位置 pos 开始的 len 个字符
 * void clear();									删除字符串中所有字符
 *
 * string大小写转换：tolower() 和 toupper() 或者 STL中的 transform 算法
 *
 * string的查找：find
 * string s("dog bird chicken bird cat");
 * 字符串查找-----找到后返回首字母在字符串中的下标
 * 1. 查找一个字符串
 * cout << s.find("chicken") << endl;  结果是：9
 * 2. 从下标为6开始找字符'i'，返回找到的第一个i的下标
 * cout << s.find('i', 6) << endl;  结果是：11
 * 3. 从字符串的末尾开始查找字符串，返回的还是首字母在字符串中的下标
 * cout << s.rfind("chicken") << endl;  结果是：9
 * 4. 从字符串的末尾开始查找字符
 * cout << s.rfind('i') << endl;  结果是：18
 * 5. 在该字符串中查找第一个属于字符串s的字符
 * cout << s.find_first_of("13br98") << endl;  结果是：4("b")
 * 6. 在该字符串中查找第一个不属于字符串s的字符，先匹配dog，然后bird匹配不到，所以打印4
 * cout << s.find_first_not_of("hello dog 2006") << endl;  结果是：4
 * 7. 在该字符串从后往前查找第一个属于字符串s的字符
 * cout << s.find_last_of("13r98") << endl;   结果是：19
 * 8. 在该字符串从后往前查找第一个不属于字符串s的字符，先匹配tac，然后空格匹配不到，所以打印21
 * cout << s.find_last_not_of("teac") << endl;  结果是：21
 *
 * string的排序
 * sort(iterator iter1, iterator iter2);  对[iter1, iter2)进行排序
 *
 * string的分割/截取字符串：substr()
 * string s1("0123456789");
 * string s2 = s1.substr(2, 5);
 * cout << s2 << endl;  结果：23456，参数5表示截取的字符串的长度
 *
 * int转string: c++11标准增加了全局函数 std::to_string
 * string转int: 可以使用std::stoi/stol/stoll等函数
 */

/* C++ 常用数据结构 */
/* array
 * #include <array>
 * array<int, 10> arr;
 * for (auto it = arr.begin(); it != arr.end(); it++)
 * 	cout << *it << '\t';
 * arr.size();
 */

/* queue
 * #include <queue>
 * queue<int> q;
 * q.push(num); q.empty(); q.size(); q.front(); q.back(); q.pop();
 */

/* priority_queue <Type, Container, Functional> : 优先队列具有最高级先出 (first in, largest out)的行为特征
 * Type 数据类型
 * Container 容器类型 (必须是用数组实现的容器, 如vector, deque等，但不能用 list, STL里默认用vector)
 * Functional 比较方式
 * pq.push(); pq.pop(); pq.top(); pq.empty(); pq.size()
 * 默认是大顶堆 priority_queue<int, vector<int>, less<int>> pq;
 * #include <functional> : greater 和 less 是 std 实现的两个仿函数 (类中实现一个operator())
 * 用 pair 做优先队列元素：pair<int, int> 先比较第一个元素, 第一个相等比较第二个.
 * 自定义类型做优先队列元素 :  重写仿函数
 * struct compare {
 *    bool operator()(type a, type b) {
 *        return a.x < b.x;   * 大顶堆
 *    }
 * };
 * priority_queue<type, vector<type>, compare> pq;
 */

/* stack
 * #include <stack>
 * stack<int> st; st.push(num); st.empty(); st.size(); st.top(); st.pop();
 */

/* list 双向链表
 * #include <list>
 * int nums[] = {1, 2, 3, 4, 5};
 * list<int> li(nums, nums + sizeof(nums) / sizeof(int));
 * auto it = li.begin();
 * li.insert(it, num);
 * li.front(); li.back(); li.pop_front(); li.pop_back(); li.push_back(); li.push_front();
 * li.assign(); li.size(); li.resize(); li.unique(); li.erase(); li.clear(); li.empty();
 */

/* #include <map>
 * map 底层为红黑树, 所有元素根据键值key自动排序, 不允许有键值相同的元素,
 * multimap 中的key可以重复, 单个元素版本的 insert() 返回值不再是一个pair, 而是一个iterator, 不再提供 operator[] 接口.
 *
 * C++11中4个关联式容器：unordered_map/unordered_set/unordered_multimap/unordered_multiset,
 * unordered_map 底层实现是哈希桶, empty(), insert(), erase(), 其 erase() 操作会缩容，导致元素重新映射，降低性能.
 * 若需要一个有序序列，使用红黑树系列的关联式容器; 若需要更高的查询效率，使用以哈希表为底层的关联式容器.
 *
 * map<char, int> m;
 * m['a'] = 1;
 * m.insert(pair<char, int>('b', 2));  make_pair内敛函数, 返回一个pair对象
 * m.erase('a');
 * auto it = m.find('b');
 * cout << it->first << it->second << endl;
 */

/* unordered_map
 * find() 判断某键值是否存在, map.find(key) == map.end() 时不存在
 * count() 统计key值在map中出现的次数
 */

/* set
 * #include <set>
 * int nums[] = {1, 2, 3, 4, 5};
 * set<int> s(nums, nums + sizeof(nums) / sizeof(int));
 * s.insert(6);
 * s.erase(2);
 * auto it = s.find(3);
 * cout << *it << endl;
 */

/* vector
 * #include <vector>
 * vector<int> vec; push_back(num); pop_back(); back(); empty(); size(); reverse()
 */

/* bitset
 * bitset的大小在编译时就需要确定
 * 定义bitset, bitset<16> b;
 * b.size() 	 返回位数
 * b.count() 	 返回1的个数
 * b.any() 		 返回是否有1
 * b.none() 	 返回是否没有1
 * b.set() 		 全部变成1
 * b.set(i) 	 将i+1位变成1
 * b.set(i,x) 	 将i+1位变成x
 * b.reset() 	 全部都变成0
 * b.flip() 	 全部去翻
 * b.to_string() 转为string类型
 */

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

/* DFS 深度优先搜索之最大岛屿面积 */
class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty()) {
                        auto [r, c] = island.top();
                        island.pop();
                        for (int k = 0; k < 4; ++k) {
                            x = r + directions[k], y = c + directions[k+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
};
/* 递归 主函数遍历所有搜索位置，判断是否可以开始搜索，辅函数递归进行搜索 */
class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + directions[i], y = c + directions[i+1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                area += dfs(grid, x, y);
        }
        return area;
    }
};

/* 使用 DFS 求解回溯算法 */
result = []
def backtrack(路径, 选择列表):
	if 满足结束条件:
		result.add(路径)
		return
	for 选择 in 选择列表:
		做选择
		backtrack(路径, 选择列表)
		撤销选择

/* 回溯算法之N皇后问题 */
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

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool isNegative = num < 0;
        if (isNegative) num = -num;
        while (num) {
            int a = num / 7, b = num % 7;
            res = to_string(b) + res;
            num = a;
        }
        return isNegative ? "-" + res : res;
    }
};

n的阶乘后面有多少个0
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);  // 统计质因子5的个数
    }
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
class Solution {
private:
    vector<int> pre, mid, post;
public:
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        preorder(root);
        midorder(root);
        postorder(root);
        res = {pre, mid, post};
        return res;
    }
    void preorder(TreeNode* root) {
        if (!root) return;
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void midorder(TreeNode* root) {
        if (!root) return;
        midorder(root->left);
        mid.push_back(root->val);
        midorder(root->right);
    }
    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->val);
    }
};

// 406--根据身高重建队列
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        for (int i = 0; i < people.size(); ++i) {
            if (people[i][1] >= res.size())
                res.push_back(people[i]);
            else
                res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

文件查找
(1)find: 根据文件属性进行查找，如文件名，文件大小，所有者，所属组，是否为空，访问时间，修改时间等。 find . -name '*.txt'
(2)grep: 根据文件内容进行查找，会对文件每一行按照给定模式(patter)进行匹配查找。 grep "text" *

ls | head -n 20
给每项文件前面增加一个id编号: ls | cat -n

find是实时查找,如果需要更快的查询,可试试locate,locate会为文件系统建立索引数据库,如果有文件更新,需要定期执行更新命令来更新索引库,以获得最新的文件索引信息.

top: 用户空间、内核空间CPU利用率，负载因子，内存使用情况，实时显示各进程的资源占用
ps -ef 查看全格式的全部进程

typedef与#define的区别
typedef是编译期行为,有类型检查功能,有自己的作用域
#define是预编译期行为，发生在预处理阶段，只进行简单文本替换，不进行任何检查,没有作用域限制

MySQL数据库优化的八种方式:
1、选取最适用的字段属性
将表中字段宽度设得尽可能小,减少不必要的空间
尽量把字段设置为NOTNULL,执行查询时,数据库不用去比较NULL值
某些文本字段,如省份/性别,可以定义为ENUM类型,MySQL中ENUM类型被当作数值型数据来处理,其速度比文本类型快得多
2、使用连接(JOIN)来代替子查询(Sub-Queries)
连接无需在内存中创建临时表来完成逻辑上需要两个步骤的查询工作
3、使用联合(UNION)来代替手动创建的临时表
4、事务
5、锁定表
6、使用外键
7、使用索引
8、优化的查询语句

linux可以通过ulimit命令查看栈上限和设置上限: ulimit -a (查看进程所有资源上限)

同一进程间的线程共享的资源有4个：堆、全局变量、静态变量、文件等公用资源
独享的资源有：栈、寄存器

select和epoll对于用户态和内核态消耗的不同：select基于用户态，epoll红黑树基于内核态

第一次握手失败：第一次SYN传输失败，两端都不会申请资源。
第二次握手失败：服务端发送的SYN+ACK传输失败，客户端未收到响应，不会申请资源，虽然服务端申请了资源，但是迟迟收不到客户端的ACK，也会将该资源释放。
第三次握手失败:
第三次握手的ACK传输失败，导致服务端迟迟没有收到ACK，就会释放资源，这时客户端认为自己已经连接好了，就会给服务端发送数据，
服务端由于没有收到第三次握手，就会以RST包对客户端响应。
但是实际上服务端会因为没有收到客户端的ACK多次发送SYN+ACK，次数是可以设置的，如果最后还是没有收到客户端的ACK，则释放资源。

拥塞控制：防止过多数据注入到网络中，使网络中的路由器或链路不致过载。
拥塞控制所要做的有一个前提：网络能够承受现有的网络负荷。
拥塞控制是一个全局性的过程，涉及到所有的主机、路由器，以及与降低网络传输性能有关的所有因素。

流量控制：指点对点通信量的控制，是端到端正的问题。流量控制所要做的就是抑制发送端发送数据的速率，以便使接收端来得及接收。
拥塞控制代价：需要获得网络内部流量分布的信息。在实施拥塞控制之前，还需要在结点之间交换信息和各种命令，以便选择控制的策略和实施控制。
这样就产生了额外的开销。拥塞控制还需要将一些资源分配给各个用户单独使用，使得网络资源不能更好地实现共享。

几种拥塞控制方法：慢开始(slow-start)、拥塞避免(congestion avoidance)、快重传(fast retransmit)和快恢复(fast recovery)

慢启动的阈值是在第二次握手时协商的,“慢”并非指cwnd增长速率慢,而是指在TCP开始发送报文段时先设置cwnd=1,使发送方开始时只发送一个报文段(试探网络拥塞情况),再逐渐增大cwnd
为了防止拥塞窗口cwnd增长过大引起网络拥塞，还需要设置一个慢开始门限ssthresh状态变量。慢开始门限ssthresh的用法如下：
当 cwnd < ssthresh 时，使用上述的慢开始算法。
当 cwnd > ssthresh 时，停止使用慢开始算法而改用拥塞避免算法。
当 cwnd = ssthresh 时，既可使用慢开始算法，也可使用拥塞控制避免算法。

拥塞避免算法：让拥塞窗口cwnd缓慢地增大，即每经过一个往返时间RTT就把发送方的拥塞窗口cwnd加1，而不是加倍。
这样拥塞窗口cwnd按线性规律缓慢增长，比慢开始算法的拥塞窗口增长速率缓慢得多。

无论在慢开始阶段还是在拥塞避免阶段，只要发送方判断网络出现拥塞（没有收到确认），就要把慢开始门限ssthresh设置为出现拥塞时的发送方窗口值的一半（但不能小于2）。
然后把拥塞窗口cwnd重新设置为1，执行慢开始算法。这样做的目的就是要迅速减少主机发送到网络中的分组数，使得发生 拥塞的路由器有足够时间把队列中积压的分组处理完毕。

linux中open和fopen的区别:
1.层次不同,open是系统调用,返回文件句柄,即文件在文件描述符表里的索引;fopen是ANSIC标准C语言库函数，返回一个指向文件结构的指针(文件流)
linux中的系统函数是open,fopen是其封装函数,fopen的实现要调用open。
2.fopen和open最主要的区别是是否有缓存
fopen用户态下有缓存,它使用FILE结构保存缓冲数据,在进行read/write时减少了用户态和内核态的切换
open没有缓存,每次读操作都直接从文件系统中获取数据,在进行read和write的时候每次都需要进行内核态和用户态的切换
表现为,如果顺序访问文件,fopen系列的函数要比直接调用open系列快;如果随机访问文件open要比fopen快
3.一般用fopen打开普通文件,用open打开设备文件

TCP/IP：应用层、传输层、网际层、网络接口层（强调这一层是为了解决不同网络的互联问题）
不过从实质上讲，TCP/IP只有最上面三层，因为最下面的网络接口层并没有什么具体内容。
因此在学习计算机网络原理时往往采取折中的办法，即综合OSI和TCP/IP的优点，采取一种只有五层协议的体系结构：物理层、数据链路层、网络层、传输层、应用层

交换机工作在OSI的第2层-数据链路层，路由器工作在OSI的第3层-网络层。

堆与栈的区别有：
1、栈由系统自动分配，而堆是人为申请开辟；
2、栈获得的空间较小，而堆获得的空间较大；
3、栈由系统自动分配，速度较快，而堆一般速度比较慢；
4、栈是连续的空间，而堆是不连续的空间。

中断一般三类：
外中断：由CPU外部引起，如I/O中断、时钟中断；
内中断（异常，陷入）：CPU内部事件或程序执行中引起，例如地址越界、浮点溢出；
在程序中使用系统调用引起。

中断处理：一般分为中断响应、中断处理两个步骤，中断响应由硬件实施，中断处理主要由软件实施。

中断处理程序的处理过程：
1. 测定是否有未响应的中断信号。
2. 保护被中断进程的CPU环境。
3. 转入相应的设备处理程序。
4. 中断处理。
5. 恢复CPU的现场并退出中断。

connect()在第二次握手后返回，accept()过程发生在三次握手之后，三次握手完成后，客户端和服务器就建立了tcp连接并可以进行数据交互了。这时可以调用accept函数获得此连接。

为什么重载与函数返回类型无关：如果不去关心函数返回值，仅仅只是调用

构造函数能不能是虚函数：不能，在调用构造函数时，虚表指针并未在对象内存空间，必须构造函数调用完成后才能形成虚表指针

TCP的四次挥手过程？2MSL的MSL是什么以及作用是什么？为什么报文有最大生存时间？
这个最大生存时间是由什么决定的（在网络传输中的哪一层及哪个设备决定,内核参数,可人为修改）？
四次挥手能减少一次吗应该怎么设计来减少一次挥手？(我是设计说在第二次挥手的时候携带一些信息，例如是否还有信息需要传送或者直接携带上剩下需要传送的信息。)

netstat: 显示网络相关信息，如网络连接、路由表、接口状态等等
linux中查看某个端口是哪个进程在运行: netstat -anp|grep 3306 (结束该进程kill -9 3005)
查看占内存最多的进程: top 然后按下P

static可以修饰构造函数？
被static修饰的成员，是随着类的加载而存在，无须创建对象而可以直接被调用，而构造函数是给对象初始化的，它的存在必须依赖于对象而存在。

构造方法是一种特殊的方法:
1.构造方法的名字必须与定义他的类名完全相同，没有返回类型.
2.创建一个对象时用new,作用是初始化.
3.每个类可以有零个或者多个构造方法.(其中参数列表不同).可以被重载.
4.不能被static、final、synchronized、abstract和native修饰。构造方法不能被子类继承。
5.构造方法在创建对象时自动执行,一般不能显式地直接调用.

怎么保证数据一致性: Redis只做缓存，不做更新

单例模式如果有两个线程都创建单例对象怎么做: 使用锁机制; 利用静态变量只能被new一次的特点

docker

malloc、vmalloc、kmalloc的区别：
1、kmalloc、vmalloc分配的是内核内存,malloc分配的是用户内存
2、kmalloc保证分配的内存在物理上是连续的,内存只有在要被DMA访问时才需要物理上连续，malloc和vmalloc保证的是在虚拟地址空间上连续
3、kmalloc能分配的大小有限,vmalloc和malloc能分配的大小相对较大
4、vmalloc比kmalloc要慢。
尽管在某些情况下才需要物理上连续的内存块，但是很多内核代码都用kmalloc来获得内存，而不是vmalloc。
这主要是出于性能的考虑。vmalloc函数为了把物理内存上不连续的页转换为虚拟地址空间上连续的页，必须专门建立页表项。
糟糕的是，通过vmalloc获得的页必须一个个地进行映射，因为它们物理上是不连续的，这就会导致比直接内存映射大得多的TLB抖动。
vmalloc仅在不得已时才会用--典型的就是为了获得大块内存时。


cl /d1 reportSingleClasslayout类名 文件名
typeid(x).name()

当调用一个对象的非静态成员函数时，系统会把该对象的起始地址赋给成员函数的this指针。
而静态成员函数不属于某一对象（所有对象共有，没有this指针，不能访问本类中非静态成员），它与任何对象都无关。

c++规定const静态类成员可以直接初始化，其他非const的静态类成员需要在类外初始化，且不能使用static关键字。
静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。

虚基类：被“virtual”继承的类，任何类都可以成为虚基类。
虚基类解决多重多级继承造成的二义性问题。

模板出现不能解决的类型，通过第三代具体化来解决。
template<> 返回值 函数名<具体类型>(参数)
类模板不能自动类型推导，函数模板可以。
类模板做函数参数(显示指定类型、参数模板化、整体模板化)
空参数实参列表限定编译器只能通过模板匹配。
模板二次编译进行检测。
成员函数在运行时才去创建。

无法解析的外部命令 通常链接阶段出错
建议：模板不要分文件编写(.h声明和.cpp实现链接不到一起,类模板的成员函数运行时才创建)，写到一个类中即可，类内声明和实现，最后把后缀改为.hpp 约定俗成

静态转换：static_cast<>()
动态转换：dynamic_cast<>()  严格  基础数据类型不可转换 丢失精度或者不安全都不可转换  发生多态可以转换
常量转换：const_cast<>()  只针对指针、引用的转换
重新解释转换：reinterpret_cast<>()  最不安全

栈解旋：从try开始，到throw抛出异常之前，所有栈上的对象都会被释放，这个过程即栈解旋。

异常的接口声明(抛出特定类型异常)  void func() throw(int,char){}

string转char *： .c_str()

cin.get()
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
查看标志位：cin.fail()
0正常 1不正常  cin.clear() 重置标志位  cin.sync() 清空缓冲区

从文件中读取元素向向量中添加：
ifstream in("data.txt");
vector<int> a;
for (int i; in >> i) { a.push_back(i); }

设置随机数种子：
#include <ctime>
srand(unsigned int) time(NULL);

容器：存放数据，STL容器是一种class template。
算法：STL算法是一种function template。
迭代器：容器与算法之间的胶合剂，共有五种类型，所有STL容器都附带有自己专属的迭代器，原生指针也是一种迭代器。
仿函数：行为类似函数，可作为算法的某种策略，是一种重载了operator()的class或class template。
适配器：用来修饰容器或仿函数或迭代器接口。
空间配置器：负责空间的配置与管理，是一个实现了动态空间配置、空间管理、空间释放的class template。

仿函数( 重载() )：函数对象调用的时候像函数调用
myCompare mc;
mc();

equal_range():返回两个迭代器  lower_bound()  upper_bound()

谓词：普通函数或者仿函数返回值bool类型

匿名函数 lambda表达式： [](){};

常用算法：
find()     // 查值
find_if()  // 按条件查找
binary_search()
count()
count_if()
merge()
random_shuffle()
sort()
reverse()
copy()
copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));  // 打印vector v中的元素
resize()
replace()
replace_if()
swap()
accumulate()
fill()

C++中public、protect、private的访问权限控制
访问权限
一个类的public成员变量、成员函数，可以通过类的成员函数、类的实例变量进行访问。
一个类的protected成员变量、成员函数，无法通过类的实例变量进行访问。但是可以通过类的友元函数、友元类进行访问。
一个类的private成员变量、成员函数，无法通过类的实例变量进行访问。但是可以通过类的友元函数、友元类进行访问。

继承权限
public继承
派生类通过public继承，基类的各种权限不变 。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，可以访问基类的public成员，但是无法访问protected、private成员，仿佛基类的成员之间加到了派生类一般。
可以将public继承看成派生类将基类的public,protected成员囊括到派生类，但是不包括private成员。

protected继承
 派生类通过protected继承，基类的public成员在派生类中的权限变成了protected 。protected和private不变。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，无法访问基类的任何成员，因为基类的public成员在派生类中变成了protected。
可以将protected继承看成派生类将基类的public,protected成员囊括到派生类，全部作为派生类的protected成员，但是不包括private成员。
private成员是基类内部的隐私，除了友元，所有人员都不得窥探。派生类的友元，都不能访问

private继承
派生类通过private继承，基类的所有成员在派生类中的权限变成了private。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，无法访问基类的任何成员，因为基类的所有成员在派生类中变成了private。
可以将private继承看成派生类将基类的public,protected成员囊括到派生类，全部作为派生类的private成员，但是不包括private成员。
private成员是基类内部的隐私，除了友元，所有人员都不得窥探。派生类的友元，都不能访问

总结：继承修饰符，就像是一种筛子，将基类的成员筛到派生类。public、protected、private，就是筛子的眼。
通过public继承，所有基类成员（除了private），public、protected都到了派生类里面，public筛眼比较大，不会改变访问权限。
通过protected继承，所有基类成员（除了private），public、protected都到了派生类里面，protected筛眼大小适中，所有过来的成员都变成了protected。
通过private继承，所有基类成员（除了private），public、protected都到了派生类里面，private筛眼最小，所有过来的成员都变成了private。

extern：置于变量或函数前，标示其定义在别的文件中，提示编译器在其他模块中寻找。也可用来指定链接。
extern “C”：C++调用C函数需要extern C，因为C语言没有函数重载。

static：修饰局部变量时，使得被修饰的变量成为静态变量，存储在静态区。其生命周期与程序相同，在main函数之前初始化，程序退出时销毁。（无论是局部静态还是全局静态）。
此外，static限制了链接属性，被修饰的全局变量只能被包含该定义的文件访问（多文件编译时，隐藏），在C++中还可以实现不同对象之间数据共享。

volatile：“易变的”，因为访问寄存器要比访问内存单元快,所以编译器一般会作减少存取内存的优化，但可能会读脏数据。
当要求使用volatile声明变量值时，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。
精确地说就是，遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问；
如果不使用valatile，则编译器将对所声明的语句进行优化。
（简洁的说就是：volatile关键词影响编译器编译的结果，用volatile声明的变量表示该变量随时可能发生变化，与该变量有关的运算，不要进行编译优化，以免出错）

const：防止变量被修改，必须定义时初始化。对于指针又分为顶层和底层，表示指针本身或指向内容的修改。
可通过const_cast进行类型转换。（函数的值传递会创建临时变量，不会改变实参，加不加const无影响，即无法重载进行区分）

C++中四种类型转换是：static_cast, dynamic_cast, const_cast, reinterpret_cast
1、const_cast：用于将const变量转为非const
2、static_cast：用于各种隐式转换，比如非const转const，void*转指针等, static_cast能用于多态向上转化，如果向下转能成功但是不安全，结果未知；
3、dynamic_cast：用于动态类型转换。只能用于含有虚函数的类，用于类层次间的向上和向下转化。只能转指针或引用。向下转化时，如果是非法的对于指针返回NULL，对于引用抛异常。要深入了解内部转换的原理。
向上转换：指的是子类向基类的转换
向下转换：指的是基类向子类的转换
它通过判断在执行到该语句的时候变量的运行时类型和要转换的类型是否相同来判断是否能够进行向下转换。
4、reinterpret_cast：几乎什么都可以转，比如将int转指针，可能会出问题，尽量少用；

5、为什么不使用C的强制转换？
C的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。

C/C++ 中指针和引用的区别？
1.指针保存所指对象的地址，有自己的空间，而引用只是所指对象的别名，指针通过解引用间接访问，而引用是直接访问；
2.使用sizeof看一个指针的大小是4，而引用则是被引用对象的大小；
3.指针可以被初始化为NULL，而引用必须被初始化且必须是一个已有对象 的引用；
4.作为参数传递时，指针需要被解引用才可以对对象进行操作，而直接对引 用的修改都会改变引用所指向的对象；
5.可以有const指针，但是没有const引用；
6.指针在使用中可以指向其它对象，但是引用只能是一个对象的引用，不能 被改变；
7.指针可以有多级指针（**p），而引用至于一级；
8.指针和引用使用++运算符的意义不一样；
9.如果返回动态内存分配的对象或者内存，必须使用指针，引用可能引起内存泄露。

一个一维int数组的数组名实际上是一个int* const 类型；
一个二维int数组的数组名实际上是一个int (*const p)[n];
数组名做参数会退化为指针，除了sizeof

内存对齐的原则
从0位置开始存储；
变量存储的起始位置是该变量大小的整数倍；
结构体总的大小是其最大元素的整数倍，不足的后面要补齐；
结构体中包含结构体，从结构体中最大元素的整数倍开始存；
如果加入pragma pack(n) ，取n和变量自身大小较小的一个。
内联函数有什么优点？内联函数与宏定义的区别？

宏定义在预编译的时候就会进行宏替换；
内联函数在编译阶段，在调用内联函数的地方进行替换，减少了函数的调用过程，但是使得编译文件变大。
因此，内联函数适合简单函数，对于复杂函数，即使定义了内联编译器可能也不会按照内联的方式进行编译。
内联函数相比宏定义更安全，内联函数可以检查参数，而宏定义只是简单的文本替换。因此推荐使用内联函数，而不是宏定义。
使用宏定义函数要特别注意给所有单元都加上括号，#define MUL(a, b) a * b，这很危险，正确写法：#define MUL(a, b) ((a) * (b))

引用的本质就是所引用对象的地址。

C++里面的四个智能指针: auto_ptr, shared_ptr, weak_ptr, unique_ptr 其中后三个是c++11支持，并且第一个已经被11弃用。

野指针就是指向一个已删除的对象或者未申请访问受限内存区域的指针。

为什么析构函数必须是虚函数？为什么C++默认的析构函数不是虚函数？
将可能会被继承的父类的析构函数设置为虚函数，可以保证当我们new一个子类，然后使用基类指针指向该子类对象，释放基类指针时可以释放掉子类的空间，防止内存泄漏。
C++默认的析构函数不是虚函数是因为虚函数需要额外的虚函数表和虚表指针，占用额外的内存。
而对于不会被继承的类来说，其析构函数若是虚函数，会浪费内存。只有需要作父类时才设为虚函数。

为了实现多态进行动态绑定，将派生类对象指针绑定到基类指针上，对象销毁时，如果析构函数没有定义为虚函数，则会调用基类的析构函数，显然只能销毁部分数据。
如果要调用对象的析构函数，就需要将该对象的析构函数定义为虚函数，销毁时通过虚函数表找到对应的析构函数。

virtual ~myClass() = 0;

析构函数与构造函数对应，当对象结束其生命周期，如对象所在函数调用完毕，系统会自动执行析构函数

静态函数和虚函数的区别：静态函数在编译时就已经确定运行时机，虚函数在运行时动态绑定。虚函数因为用了虚函数表机制，调用的时候会增加一次内存开销。

多态：多态的实现主要分为静态多态和动态多态，静态多态主要是模板技术和函数重载，在编译时确定；
动态多态采用虚函数机制，通过继承关系重写基类的虚函数，在运行期间动态绑定。
举个例子：一个父类类型的指针指向一个子类对象时候，使用父类的指针去调用子类中重写了的父类中的虚函数的时候，会调用子类重写过后的函数，
在父类中声明为加了virtual关键字的函数，在子类中重写时候不需要加virtual也是虚函数。

虚函数的作用：用于实现多态，在设计上还具有封装和抽象的作用。

虚函数的实现：在有虚函数的类中，类的最开始部分是一个虚函数表的指针，这个指针指向一个虚函数表，表中放了虚函数的地址，
实际的虚函数在代码段(.text)中。当子类继承了父类的时候也会继承其虚函数表，当子类重写父类中虚函数时候，会将其继承到的虚函数表中的地址替换为重新写的函数地址。
使用了虚函数，会增加访问内存开销，降低效率。

++i 实现：int&  int::operator++（）{  *this +=1；return *this；}
i++ 实现：const int  int::operator（int）{  int oldValue = *this；++（*this）；return oldValue；}

写个函数在main函数执行前先运行：
__attribute((constructor))void before() { printf("before main\n"); }

__attribute((constructor))是gcc扩展，标记这个函数应当在main函数之前执行。同样__attribute((destructor))，
标记函数应当在程序结束之前（main结束之后，或者调用了exit后）执行。

C++里是怎么定义常量的？常量存放在内存的哪个位置？
常量在C++里的定义就是一个top-level const加上对象类型，常量定义必须初始化。
对于局部对象，常量存放在栈区，对于全局对象，常量存放在全局/静态存储区。对于字面值常量，常量存放在常量存储区。

智能指针shared_ptr的实现：核心要理解引用计数，什么时候销毁底层指针，还有赋值，拷贝构造时候的引用计数的变化，
析构的时候要判断底层指针的引用计数为0了才能真正释放底层指针的内存。

以下四行代码的区别是什么？
const char * arr = "123"; char * brr = "123"; const char crr[] = "123"; char drr[] = "123";

const char * arr = "123";
字符串123保存在常量区，const本来是修饰arr指向的值不能通过arr去修改，但是字符串“123”在常量区，本来就不能改变，所以加不加const效果都一样

char * brr = "123";
字符串123保存在常量区，这个arr指针指向的是同一个位置，同样不能通过brr去修改"123"的值

const char crr[] = "123";
123本来是在栈上的，但是编译器可能会做某些优化，将其放到常量区

char drr[] = "123";
字符串123保存在栈区，可以通过drr去修改

C++函数栈空间的最大值：默认是1M，不过可以调整。

new/delete与malloc/free的区别是什么：new/delete是C++关键字，而malloc/free是C语言库函数，后者使用必须指明申请内存空间的大小，
对于类类型的对象，后者不会调用构造函数和析构函数。new是分配在自由存储区而malloc分配在堆上，自由存储区可以是堆也可以不是，具体要看new内部的实现。

说说你了解的RTTI：
运行时类型检查，在C++层面主要体现在dynamic_cast和typeid,VS中虚函数表的-1位置存放了指向type_info的指针。
对于存在虚函数的类型，typeid和dynamic_cast都会去查询type_info

虚函数表具体是怎样实现运行时多态的?
编译器为每一个类维护一个虚函数表，虚函数表是类对象之间共享的，子类若重写父类虚函数，虚函数表中，该函数的地址会被替换，
对于存在虚函数的类的对象，在VS中，对象的头部存放指向虚函数表的指针，对虚函数指针的地址解引用得到虚函数表的地址。

C语言是怎么进行函数调用的：每一个函数调用都会分配函数栈，在栈内进行函数执行过程。调用前，先把返回地址压栈，然后把当前函数的esp指针压栈。

C语言参数压栈顺序：从右到左

C++如何处理返回值：生成一个临时变量，把它的引用作为函数参数传入函数内。

C++中拷贝赋值函数的形参能否进行值传递？
不能。如果是这种情况下，调用拷贝构造函数的时候，首先要将实参传递给形参，这个传递的时候又要调用拷贝构造函数。。如此循环，无法完成拷贝，栈也会满。

1. 不要在析构函数中抛出异常！虽然C++并不禁止析构函数抛出异常，但这样会导致程序过早结束或出现不明确的行为（abort导致程序非正常退出）。
2. 如果某个操作可能会抛出异常，class应提供一个普通函数（而非析构函数），来执行该操作。目的是给客户一个处理错误的机会。
3. 如果析构函数中异常非抛不可，那就用try catch来将异常吞下，但这样并不好，我们提倡有错早些报出来。

1. 构造函数中抛出异常，会导致析构函数不能被调用，但对象本身已申请到的内存资源会被系统释放（已申请到资源的内部成员变量会被系统依次逆序调用其析构函数）。
2. 因为析构函数不能被调用，所以可能会造成内存泄露或系统资源未被释放。
3. 构造函数中可以抛出异常，但必须保证在构造函数抛出异常之前，把系统资源释放掉，防止内存泄露。（如何保证？使用auto_ptr）

不要在构造函数中调用虚函数：因为父类对象会在子类之前进行构造，此时子类部分的成员还未初始化， 因此调用子类的虚函数是不安全的。
不要在析构函数中调用虚函数：析构函数在销毁一个对象时，先调用子类析构，再调用基类析构，此时派生类对象的数据成员已经“销毁”，再调用子类虚函数没有意义。

智能指针能够帮助我们处理资源泄露、空悬指针、比较隐晦的由异常造成的资源泄露问题。
 1 #include <iostream>
 2 using namespace std;
 3
 4 int main()
 5 {
 6     int *ptr = new(nothrow) int(0);
 7     if(!ptr)
 8     {
 9         cout << "new fails."
10         return 0;
11     }
12     // 假定hasException函数原型是 bool hasException()
13     if (hasException())
14         throw exception();
15
16     delete ptr;
17     ptr = nullptr;
18     return 0;
19 }

1 // 假定hasException函数原型是 bool hasException()
2 if (hasException())
3 {
4         delete ptr;
5         ptr = nullptr;
6         throw exception();
7 }

1. Class shared_ptr实现共享式拥有，多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用被销毁”时释放。为了在结构复杂情境中执行上述工作，标准库提供了weak_ptr、bad_weak_ptr和enable_shared_from_this等辅助类。
2. Class unique_ptr实现独占式拥有，保证同一时间只有一个智能指针可以指向该对象。它对于避免资源泄露（resourece leak）——例如“以new创建对象后因为发生异常而忘记调用delete”——特别有用。

shared_ptr本身提供默认内存释放器（default deleter），调用的是delete，不过只对“由new建立起来的单一对象”起作用。
1 shared_ptr<int> pJutta2(new int[10],
2         // deleter (a lambda function)
3         [](int *p)
4         {
5             delete[] p;
6         }
7     );
或者使用为unique_ptr而提供的辅助函数作为内存释放器，其内调用delete[]：
1 shared_ptr<int> p(new int[10], default_delete<int[]>());

1 #include <memory>
2 using namespace std;
3
4 int main()
5 {
6     unique_ptr<int> ptr(new int(0));
7     return 0;
8 }

基于引用计数的智能指针可以简单实现如下
#include <iostream>
using namespace std;

template<class T>
class SmartPtr {
public:
    SmartPtr(T *p);
    ~SmartPtr();
    SmartPtr(const SmartPtr<T> &orig);                // 浅拷贝
    SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // 浅拷贝
private:
    T *ptr;
    // 将use_count声明成指针是为了方便对其的递增或递减操作
    int *use_count;
};

template<class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p) {
    try {
        use_count = new int(1);
    }
    catch (...) {
        delete ptr;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Allocate memory for use_count fails." << endl;
        exit(1);
    }
    cout << "Constructor is called!" << endl;
}

template<class T>
SmartPtr<T>::~SmartPtr() {
    // 只在最后一个对象引用ptr时才释放内存
    if (--(*use_count) == 0) {
        delete ptr;
        delete use_count;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Destructor is called!" << endl;
    }
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig) {
    ptr = orig.ptr;
    use_count = orig.use_count;
    ++(*use_count);
    cout << "Copy constructor is called!" << endl;
}

// 重载等号函数不同于复制构造函数，即等号左边的对象可能已经指向某块内存。
// 这样，我们就得先判断左边对象指向的内存已经被引用的次数。如果次数为1，
// 表明我们可以释放这块内存；反之则不释放，由其他对象来释放。
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs) {
    // 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使rhs的使用计数加1，
    // 从而防止自身赋值”而导致的提早释放内存
    ++(*rhs.use_count);

    // 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象
    if (--(*use_count) == 0) {
        delete ptr;
        delete use_count;
        cout << "Left side object is deleted!" << endl;
    }

    ptr = rhs.ptr;
    use_count = rhs.use_count;

    cout << "Assignment operator overloaded is called!" << endl;
    return *this;
}

Hash表实现（拉链和分散地址）

STL中hash_map扩容发生什么？
1、创建一个新桶，该桶是原桶两倍大最接近的质数(判断n是不是质数的方法：用n除2到sqrt(n)范围内的数)；
2、将原来桶里的数通过指针转换，插入到新桶中(注意STL这里做的很精细，没有直接将数据从旧桶遍历拷贝数据插入到新桶，而是通过指针转换)
3、通过swap函数将新桶和旧桶交换，销毁新桶。

GCC是C/C++语言的编译工具，Make是增量式（编译）批处理工具，CMake是Make脚本生成工具。
开发者需要编写CMakelist.txt文件，来配置项目相关的CMake参数。
通过运行cmake命令，自动生成对应平台的Make工具自动构建脚本Makefile文件。
当然，CMake也支持生成其他的构建工具的配置文件，比如Xcode的xxxx.xcodeproj，Visual Studio的xxxx.sln，Ninja的xxxx.ninja等等。
目前，大多数开源的C/C++项目都支持使用CMake生成Makefile文件，再调用make命令，使用Make工具进行自动构建。
Makefile文件可以看成是一系列依赖于文件的Shell命令。
它基于文件修改的时间戳来实现增量式处理。
具体规则大致如下，若生成的目标文件的时间戳早于依赖文件的时间戳时，则执行对应的命令，重新生成目标文件。
这实际上暗示了，Make工具不只用于编译，还可以用于其他的增量式文件生成任务。
使用Make工具来编译C/C++项目时，一般会使用Shell命令来调用gcc，自动化且增量式地实现C/C++源代码的编译链接等一系列工作。

GCC被重新定义为GNU Compiler Collection，即 GNU编译器套件。

Apple基于LLVM重新开发了编译工具Clang。

n & (~n + 1)提取出整数n最后一位为1的数

STL里的内存池实现
STL内存分配分为一级分配器和二级分配器，一级分配器就是采用malloc分配内存，二级分配器采用内存池。

二级分配器设计的非常巧妙，分别给8k，16k,…, 128k等比较小的内存片都维持一个空闲链表，每个链表的头节点由一个数组来维护。需要分配内存时从合适大小的链表中取一块下来。假设需要分配一块10K的内存，那么就找到最小的大于等于10k的块，也就是16K，从16K的空闲链表里取出一个用于分配。释放该块内存时，将内存节点归还给链表。
如果要分配的内存大于128K则直接调用一级分配器。
为了节省维持链表的开销，采用了一个union结构体，分配器使用union里的next指针来指向下一个节点，而用户则使用union的空指针来表示该节点的地址。

STL里set和map是基于什么实现的。红黑树的特点？

set和map都是基于红黑树实现的。
红黑树是一种平衡二叉查找树，与AVL树的区别是什么？AVL树是完全平衡的，红黑树基本上是平衡的。
为什么选用红黑数呢？因为红黑数是平衡二叉树，其插入和删除的效率都是N(logN)，与AVL相比红黑数插入和删除最多只需要3次旋转，而AVL树为了维持其完全平衡性，在坏的情况下要旋转的次数太多。
红黑树的定义：
(1) 节点是红色或者黑色；
(2) 父节点是红色的话，子节点就不能为红色；
(3) 从根节点到每个页子节点路径上黑色节点的数量相同；
(4) 根是黑色的，NULL节点被认为是黑色的。

必须在构造函数初始化式里进行初始化的数据成员有哪些
(1) 常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
(2) 引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
(3) 没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化

模板特化
(1) 模板特化分为全特化和偏特化，模板特化的目的就是对于某一种变量类型具有不同的实现，因此需要特化版本。例如，在STL里迭代器为了适应原生指针就将原生指针进行特化。

定位内存泄露
(1)在windows平台下通过CRT中的库函数进行检测；
(2)在可能泄漏的调用前后生成块的快照，比较前后的状态，定位泄漏的位置
(3)Linux下通过工具valgrind检测

什么是红黑树？
节点为红色或者黑色；
根节点为黑色；
从根节点到每个叶子节点经过的黑色节点个数的和相同；
如果父节点为红色，那么其子节点就不能为红色。

红黑树与AVL树的区别
红黑树与AVL树都是平衡树，但是AVL是完全平衡的(平衡就是值树中任意节点的左子树和右子树高度差不超过1)；
红黑树效率更高，因为AVL为了保证其完全平衡，插入和删除的时候在最坏的情况下要旋转logN次，而红黑树插入和删除的旋转次数要比AVL少。

Trie树(字典树)
每个节点保存一个字符
根节点不保存字符
每个节点最多有n个子节点(n是所有可能出现字符的个数)
查询的复杂父为O(k)，k为查询字符串长度

C语言程序能不能直接调用C++语言编写的动态链接库。
不能，因为C++支持重载，在编译函数的声明时，会改写函数名（可以通过链接指示进行解决）；另外，C语言不支持类，无法直接调用类的成员函数（可以通过加入中间层进行解决）；C语言也不能调用返回类型或形参类型是类类型的函数。

类之间的关系
（1）继承：is a子类继承父类的方法（鹅和鸟的关系）
（2）组合：has-a整体和部分的关系，整体和部分之间是不可可分离的，它们具有相同的生命周期（鸟和翅膀的关系）
（3）聚合：contains-a：整体和部分的关系，整体和部分之间是可分离的，它们可以具有各自的生命周期，部分可以属于多个整体对象，也可以为多个整体对象共享。如员工和公司之间的关系。
（4）关联：弱关系，双方一般是平等的。如明星和粉丝之间的关系。
（5）实现：实现是类和接口之间的关系。接口通过纯虚函数来实现。
（6）依赖： 简单的理解，依赖就是一个类A使用到了另一个类B，而这种使用关系是具有偶然性的、临时性的、非常弱的，但是类B的变化会影响到类A。比如某人要过河，需要借用一条船，此时人与船之间的关系就是依赖。表现在代码层面，为类B作为参数被类A在某个method方法中使用。

面对对象的设计原则：
（1）开放封闭原则：
一个软件实体应当对扩展开放，对修改关闭。
（2）里式代换原则
在任何父类出现的地方都可以用他的子类来替代。
（3）依赖倒转原则
要依赖于抽象，不要依赖于具体实现。
（4）单一职责原则
一个类应该仅有一个引起它变化的原因。
（5）接口隔离原则
使用多个专门的接口比使用单个接口要好的多。

unordered_map是如何解决哈希冲突的
（1）一个桶中可以放多个元素，元素的关键字相同；也就是通常的链地址法
（2）unordered_map会维护桶的平均元素数量，会在需要时添加新的桶，以使得load_factor<=max_load_factor

防止继承发生：在类名后跟一个关键字final。
区分前置和后置运算符：后置版本接受一个额外的（不被使用）int类型的形参。
输入输出运算符必须是非成员函数。因为IO运算符通常需要读写类的非公有数据成员，所以IO运算符一般被声明为友元。

topk （前k大）用小根堆，维护堆大小不超过 k 即可。每次压入堆前和堆顶元素比较，如果比堆顶元素还小，直接扔掉，否则压入堆。检查堆大小是否超过 k，如果超过，弹出堆顶。复杂度是 nlogk
避免使用大根堆，因为你得把所有元素压入堆，复杂度是 nlogn，而且还浪费内存。如果是海量元素，那就挂了。

[注意]求前 k 大，用小根堆，求前 k 小，用大根堆。

topk 复杂度不是 klogk，是 nlogk.
建堆，建堆复杂度是 n.
插入，logn，上浮操作。
删除（堆顶），一次 sink 操作，logn.


---------------------------------------------面试题------------------------------------------

MySQL中常用的四种存储引擎： MyISAM存储引擎、innoDB存储引擎、MEMORY存储引擎、ARCHIVE存储引擎。

1、存储引擎是对数据库文件的一种存取机制，如何实现存储数据，如何为存储的数据建立索引以及如何更新，查询数据等技术实现的方法。
2、MySQL中数据用不同的技术存储在文件（或内存）中，每一种技术都使用不同的存储机制，索引技巧，锁定水平等。在MySQL中将这些不同的技术及配套的相关功能称为存储引擎。

1、show engines; // 查看mysql所支持的存储引擎，以及mysql默认的存储引擎。
2、show variables like ‘% storage_engine’; // 查看mysql 默认的存储引擎
3、show create table tablename ; // 查看具体某一个表所使用的存储引擎，这个默认存储引擎被修改了！
4、show table status from database where name=“tablename” //准确查看某个数据库中的某一表所使用的存储引擎

MyISAM存储引擎：
存放位置： MySQL如果使用MyISAM存储引擎，数据库文件类型就包括.frm、.MYD、.MYI，默认存放位置是C:\Documentsand Settings\All Users\Application Data\MySQL\MySQL Server 5.1\data
存放方式： MyISAM 存储引擎不支持事务，不支持行级锁，只支持并发插入的表锁
索引方式： MyISAM使用B+tree索引，但是和Innodb的在具体实现上有些不同。
该引擎基于ISAM数据库引擎，除了提供ISAM里所没有的索引和字段管理等大量功能，MyISAM还使用一种表格锁定的机制来优化多个并发的读写操作，但是需要经常运行OPTIMIZE TABLE命令，来恢复被更新机制所浪费的空间，否则碎片也会随之增加，最终影响数据访问性能。MyISAM还有一些有用的扩展，例如用来修复数据库文件的MyISAMChk工具和用来恢复浪费空间的 MyISAMPack工具。

MyISAM强调了快速读取操作，主要用于高负载的select，这可能也是MySQL深受Web开发的主要原因：在Web开发中进行的大量数据操作都是读取操作

MyISAM类型的表支持三种不同的存储结构：静态型、动态型、压缩型。
静态型：指定义的表列的大小是固定（即不含有：xblob、xtext、varchar等长度可变的数据类型），这样MySQL就会自动使用静态MyISAM格式。使用静态格式的表的性能比较高，因为在维护和访问以预定格式存储数据时需要的开销很低；但这种高性能是以空间为代价换来的，因为在定义的时候是固定的，所以不管列中的值有多大，都会以最大值为准，占据了整个空间。

动态型：如果列（即使只有一列）定义为动态的（xblob, xtext, varchar等数据类型），这时MyISAM就自动使用动态型，虽然动态型的表占用了比静态型表较少的空间，但带来了性能的降低，因为如果某个字段的内容发生改变则其位置很可能需要移动，这样就会导致碎片的产生，随着数据变化的增多，碎片也随之增加，数据访问性能会随之降低。

因碎片增加而降低数据访问性，有两种解决办法：
a、尽可能使用静态数据类型；
b、经常使用optimize table table_name语句整理表的碎片，恢复由于表数据的更新和删除导致的空间丢失。如果存储引擎不支持optimize table table_name，则可以转储并重新加载数据，

压缩型：如果在数据库中创建在整个生命周期内只读的表，则应该使用MyISAM的压缩型表来减少空间的占用。

优缺点：MyISAM的优势在于占用空间小，处理速度快。缺点是不支持事务的完整性和并发性。

innoDB存储引擎
存储位置：MySQL如果使用InnoDB存储引擎，数据库文件类型就包括.frm、ibdata1、.ibd，存放位置有两个，.frm文件默认存放位置是C:\Documents and Settings\All Users\ApplicationData\MySQL\MySQL Server 5.1\data，ibdata1、.ibd文件默认存放位置是MySQL安装目录下的data文件夹。

innodb存储引擎的mysql表提供了事务，回滚，系统崩溃修复能力，多版本迸发控制的事务安全。

innodb存储引擎支持事务，以及事务相关联功能，支持mvcc的行级锁，支持外键,使用B+Tree，支持自增长列（auto_increment）

优缺点：InnoDB的优势在于提供了良好的事务处理、崩溃修复能力和并发控制。缺点是读写效率较差，占用的数据空间相对较大。

MEMORY存储引擎
memory存储引擎使用存储在内存中的数据来创建表，所有的数据都存储在内存中。每个基于memory存储引擎的表实际对应一个磁盘文件，该文件的文件名和表名相同，类型为.frm。该文件只存储表的结构，而其数据文件，都是存储在内存中，这样有利于数据的快速处理，提高表的处理能力。如果mysqld进程发生异常，重启或关闭机器这些数据都会消失。所以表的生命周期很短，一般只使用一次。

memory存储引擎默认使用哈希（HASH）索引，其速度比使用B-+Tree型要快，如果读者希望使用B树型，则在创建的时候可以引用。

ARCHIVE存储引擎
适合存储大量存储归档数据。ARCHIVE提供压缩功能，拥有高效的插入速度，但是不支持索引，所以查询性能较差。

InnoDB：支持事务处理，支持外键，支持崩溃修复能力和并发控制。如果需要对事务的完整性要求比较高（比如银行），要求实现并发控制（比如售票），那选择InnoDB有很大的优势。

MyISAM：插入数据快，空间和内存使用比较低。如果数据表主要用来插入和查询记录，则MyISAM引擎能提供较高的处理效率

MEMORY：所有的数据都在内存中，数据的处理速度快，但是安全性不高。它对表的大小有要求，不能建立太大的表。MySQL中使用该引擎作为临时表，存放查询的中间结果

注意，同一个数据库也可以使用多种存储引擎的表。如果一个表要求比较高的事务处理，可以选择InnoDB。这个数据库中可以将查询要求比较高的表选择MyISAM存储。如果该数据库需要一个用于查询的临时表，可以选择MEMORY存储引擎。

什么情况下数据库索引会失效
1.条件中有or，即使其中有条件带索引也不会使用(这也是为什么尽量少用or的原因)。注意：要想使用or，又想让索引生效，只能将or条件中的每个列都加上索引
2.对于多列索引，不是使用的第一部分，则不会使用索引
3.like查询是以%开头
4.列类型是字符串，那一定要在条件中将数据使用引号引用起来,否则不使用索引
5.mysql估计使用全表扫描要比使用索引快,则不使用索引

mysql 的索引模型：自适应哈希索引、B+树索引、有序数组索引

“读已提交”解决了脏读；“可重复读”不仅解决了脏读，还解决了不可重复读；它们的原理都是通过给数据行加锁（共享读锁和排他写锁）来完成的。

幻读：前后多次读取，数据总量不一致
幻读产生的根本原因是采用的行级锁，所以只针对脏读和重复读有用
幻读的解决方案：表级锁，mysql innodb自带版本控制

1、mysql默认引擎
mysql-5.1版本之前默认引擎是MyISAM，之后是innoDB

2、关系
MyISAM是非集聚引擎，支持全文索引；不支持事务；它是表级锁；会保存表的具体行数
innoDB是集聚引擎，5.6以后才有全文索引；支持事务；它是行级锁；不会保存表的具体行数

一般：不用事务,count计算多的时候适合myisam引擎，对可靠性要求高就用innodby引擎。

3、索引分类

1.普通索引index :加速查找
2.唯一索引
主键索引：primary key ：加速查找+约束（不为空且唯一）
唯一索引：unique：加速查找+约束 （唯一）
3.联合索引
-primary key(id,name)：联合主键索引
-unique(id,name)：联合唯一索引
-index(id,name)：联合普通索引
4.全文索引fulltext：用于搜索很长一篇文章的时候，效果最好。
5.空间索引spatial :了解就好，几乎不用

主从复制可以实现数据备份、故障转移、MySQL集群、高可用、读写分离
实现服务器负载均衡(读写分离)
通过复制实现数据的异地备份(数据备份)
提高数据库系统的可用性(故障转移)

Http和Https的区别：　　
Http协议运行在TCP之上，明文传输，客户端与服务器端都无法验证对方的身份，用于从WWW服务器传输超文本到本地浏览器的传输协议。
通信双方也没有进行任何认证，通信过程容易遭遇劫持、监听、篡改，严重情况下，会造成恶意的流量劫持等问题，
甚至造成个人隐私泄露（比如银行卡卡号和密码泄露）等严重的安全问题。
Https在Http基础上加入SSL外壳(Secure Socket Layer)，添加了加密和认证机制，运行于SSL上，SSL运行于TCP之上。
其主要作用是建立一个信息安全通道，保证数据传输安全；也可以确认网站的真实性。

二者之间存在如下不同：
端口不同：前者80，后者443；
资源消耗：和HTTP通信相比，Https通信由于加减密处理消耗更多的CPU和内存资源；
开销：Https通信需要证书，而证书一般需要向认证机构购买；Https的加密机制是一种共享密钥加密和公开密钥加密并用的混合加密机制。

一次HTTP操作称为一个事务：
地址解析；封装HTTP请求数据包；封装成TCP包，建立TCP连接（TCP的三次握手）；客户机发送请求命令；服务器响应；服务器关闭TCP连接。

HTTPS的加密算法
首先介绍两个概念：
对称秘钥:对称密钥加密又叫专用密钥加密，即发送和接收数据的双方必使用相同的密钥对明文进行加密和解密运算。通常有两种模式：流加密和分组加密。
非对称秘钥：非对称加密算法需要两个密钥：公开秘钥（publickey）和私有密钥（privatekey）。
公开密钥与私有密钥是一对，如果用公开密钥对数据进行加密，只有用对应的私有密钥才能解密；
如果用私有密钥对数据进行加密，那么只有用对应的公开密钥才能解密。
因为加密和解密使用的是两个不同的密钥，所以这种算法叫作非对称加密算法。
4.1 HTTPS保证数据安全的机制：
　　在HTTP的概念中介绍了HTTP是非常不安全的，那么在服务器与客户端传递数据的过程中HTTPS是如何保证数据的安全呢？
　　1.客户端向服务器端发起SSL连接请求；（在此过程中依然存在数据被中间方盗取的可能，下面将会说明如何保证此过程的安全）
　　2 服务器把公钥发送给客户端，并且服务器端保存着唯一的私钥；
　　3.客户端用公钥对双方通信的对称秘钥进行加密，并发送给服务器端；
　　4.服务器利用自己唯一的私钥对客户端发来的对称秘钥进行解密，在此过程中，中间方无法对其解密（即使是客户端也无法解密，因为只有服务器端拥有唯一的私钥），这样保证了对称秘钥在收发过程中的安全，此时，服务器端和客户端拥有了一套完全相同的对称秘钥。
　　5.进行数据传输，服务器和客户端双方用公有的相同的对称秘钥对数据进行加密解密，可以保证在数据收发过程中的安全，即是第三方获得数据包，也无法对其进行加密，解密和篡改。

4.2 CA（电子商务认证机构）认证作用：
　　在上面提到的 客户端向服务器端发起请求时存在数据被盗取的过程：  假如服务器端经由中间方向客户端发送公钥的时候，中间方没有将公钥发送给客户端，而是伪造了一对公钥，并将伪造的公钥发送给客户端，此时客户端用中间方伪造的公钥对自己正确的对称秘钥加密并由中间方发送给服务器端，而中间方将用自己伪造的公钥的私钥对其进行解密，得到正确的对称秘钥，并将得到的正确的对称秘钥用服务器端发过来的公钥进行加密发给服务器端，服务器daunt再用正确的私钥进行解密，也得到正确的对称秘钥，此时客户端，服务器端，中间方三者都拥有一套正确的对称秘钥，可以对传送的数据进行加密，解密。
　　为了解决上述问题，一般情况下，服务器端会向CA申请认证书，此证书包含了CA及服务器端的一些信息（可以理解为类似公章），这样，服务器端将证书发给客户端的过程中，中间方是无法伪造的，保证了，发给客户端的公钥是服务器端发送的。

让你设计一个延时任务系统怎么做 说了两个方案，一个是使用 redis 的 ZSET 来实现，考虑分片来抗高并发，使用 redis 的持久化来实现落地，使用 redis 的哨兵实现故障转移。 一个是使用时间轮的方法。

zset 实现延时队列可以以时间戳作为score存入zset，zrange --withscore 取出判断是否到了执行时间，到了则执行然后删除

string、list、set、zset、hash这五种基本数据结构，string底层是数组，list底层是链表，hash和set的底层应该都是hashmap，zset应该是跳跃表

让你设计一个限流的系统怎么做？ 令牌桶（网络中处理流控的一个经典算法）

协程相对线程更加轻量级，也被称为用户态线程


// 两个有序数组，找中位数
/* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1], pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};


// 实现atoi，字符串转整数
class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int state = 0;  //  0-初始状态  1-正数  2-负数
        for (char c : s) {
            if (state == 0 && c == ' ') continue;
            else if (state == 0 && c == '+') state = 1;
            else if (state == 0 && c == '-') state = 2;
            else if (c >= '0' && c <= '9') {
                if (state == 0) state = 1;
                int tmp = c - '0';
                res = res * 10 + tmp;
                if (res > INT_MAX) break;
            } else break;
        }
        if (state == 1 && res > INT_MAX) res = INT_MAX;
        else if (state == 2) {
            res = -res;
            if (res < INT_MIN) res = INT_MIN;
        }
        return res;
    }
};

// 给一个无序链表，如何排序？链表归并如何实现？首先快慢指针取中点分成两半，链表归并的时间复杂度

// 反转句子，但要以逗号作为分隔，样例如下：“hello world, god bless you” -> “world hello, you bless god”

------------------------------------------------------------------------------------------------------------------
了解云产品、docker、find ./ *.txt、tcp和udp、DNS本身、epoll为啥高并发、进程间通信方式、Redis数据类型、
Python、https安全机制、Webbench压力测试、Mysql数据库的优化(除了语句explain分析)
------------------------------------------------------------------------------------------------------------------