
/* sort(v.begin(), v,end(), compare); 
 * bool compare(int a, int b) { return a < b; }  升序排列(默认)
 * #include <functional>
 * 升序: sort(begin, end, less<data-type>())
 * 降序: sort(begin, end, greater<data-type>())
 */

/* #include<numeric>
 * accumulate(v.begin(), v.end(), 0);  累加起始值
 */

/* C++ string 常用函数 
 * #include <string>
 * string str;							生成空字符串
 * string s(str);						生成字符串为str的复制品
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

/* priority_queue<Type, Container, Functional> : 优先队列具有最高级先出 (first in, largest out)的行为特征
 * Type 数据类型
 * Container 容器类型 (必须是用数组实现的容器, 如vector, deque等，但不能用 list, STL里默认用vector)
 * Functional 比较方式
 * pq.push(); pq.pop(); pq.top(); pq.empty(); pq.size()
 * 默认是大顶堆 priority_queue<int, vector<int>, less<int>> pq;
 * #include<functional> : greater 和 less 是 std 实现的两个仿函数 (类中实现一个operator())
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

/* 快速排序 Quick Sort 左闭右闭二分写法 */
void quick_sort(vector<int>& nums, int l, int r) {
	if (l + 1 >= r) return;
	int first = l, last = r - 1, key = nums[first];
	while (first < last) {
		while (first < last && nums[last] >= key)
			--last;
		nums[first] = nums[last];
		while (first < last && nums[first] <= key)
			++first;
		nums[last] = nums[first];
	}
	nums[first] = key;
	quick_sort(nums, l, first);
	quick_sort(nums, first + 1, r);
}

/* 快速选择 Quick Selection */
int quickSelection(vector<int>& nums, int l, int r) {
    int i = l + 1, j = r;
    while (true) {
        while (i < r && nums[i] <= nums[l])
            ++i;
        while (l < j && nums[j] >= nums[l])
            --j;
        if (i >= j) break;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[j]);
    return j;
}
int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, target = nums.size() - k;
    while (l < r) {
        int mid = quickSelection(nums, l, r);
        if (mid == target) return nums[mid];
        else if (mid < target) l = mid + 1;
        else r = mid - 1;
    }
    return nums[l];
}

/* 归并排序 Merge Sort 
 * 分治法 
 * 1.将n个元素从中间切开，分成两部分。（左边可能比右边多1个数）
 * 2.将步骤1分成的两部分，分别进行递归分解。直到所有部分的元素个数都为1。
 * 3.从最底层开始逐步合并两个排好序的数列。
 * 合并: 由于两个数列都已经有序，只需从低位轮番拿出各自最小的数来PK就行，较小值放入临时数列。
 */
void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp) {
	if (l + 1 >= r) return;
	// divide
	int m = l + (r - l) / 2;
	merge_sort(nums, l, m, temp);
	merge_sort(nums, m, r, temp);
	// conquer
	int p = l, q = m, index = l;
	while (p < m || q < r) {
		if (q >= r || (p < m && nums[p] <= nums[q]))
			temp[index++] = nums[p++];
		else
			temp[index++] = nums[q++];
	}
	for (index = l; index < r; index++)
		nums[index] = temp[index];
}

/* 插入排序 Insertion Sort */
void insertion_sort(vector<int>& nums, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
			swap(nums[j], nums[j - 1]);
		}
	}
}

/* 冒泡排序 Bubble Sort */
void bubble_sort(vector<int>& nums, int n) {
	bool swapped;
	for (int i = 1; i < n; ++i) {
		swapped = false;
		for (int j = 1; j < n - i - 1; ++j) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

/* 选择排序 Selection Sort */
void selection_sort(vector<int>& nums, int n) {
	int mid;
	for (int i = 0; i < n - 1; ++i) {
		mid = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[mid])
				mid = j;
		}
		swap(nums[mid], nums[i]);
	}
}

/* 桶排序求前K个最频繁的数字 topKFrequent */
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> counts;
	int max_count = 0;
	for (const int & num : nums) {
		max_count = max(max_count, ++counts[num]);
	}
	vector<vector<int>> buckets(max_count + 1);
	for (const auto & p : counts) {
		buckets[p.second].push_back(p.first);
	}
	vector<int> res;
	for (int i = max_count; i >= 0 && res.size() < k; --i) {
		for (const int & num : buckets[i]) {
			res.push_back(num);
			if (res.size() == k) break;
		}
	}
	return res;
}