
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