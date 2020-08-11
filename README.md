## PRACTICE MAKES PERFECT

------



- **动态规划**的核心问题是穷举，由于这类问题存在「重叠子问题」，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程。

- 明确 base case --> 明确「状态」--> 明确「选择」 --> 定义 dp 数组/函数的含义。

- 动态规划框架：

  ```
  初始化 base case
  dp[0][0][...] = base
  进行状态转移
  for 状态1 in 状态1的所有取值：
      for 状态2 in 状态2的所有取值：
          for ...
              dp[状态1][状态2][...] = 求最值(选择1，选择2...)
  ```


- **回溯问题**，实际上就是一个决策树的遍历过程，不合适就退回上一步，通过约束条件, 减少时间复杂度。

- 回溯算法（DFS）的框架：

  ```
  result = []
  def backtrack(路径, 选择列表):
      if 满足结束条件:
          result.add(路径)
          return
       for 选择 in 选择列表:
       	做选择
       	将该选择从选择列表移除
      	路径.add(选择)
      	backtrack(路径, 选择列表)
      	撤销选择
      	路径.remove(选择)
      	将该选择再加入选择列表
  ```


- **BFS**本质：从一个起点，走到终点，问最短路径。

  ```
  // 计算从起点 start 到终点 target 的最近距离
  int BFS(Node start, Node target) {
      queue<Node> q; 		  // 核心数据结构
      set<Node> visited;  // 避免走回头路
  	  q.push(start); 		  // 将起点加入队列
  	  visited.add(start);
  	  int step = 0; 		  // 记录扩散的步数
  	  while (q not empty) {
      int sz = q.size();
      /* 将当前队列中的所有节点向四周扩散 */
      for (int i = 0; i < sz; i++) {
          Node cur = q.pop();
          if (cur is target)	     // 判断是否到达终点
              return step;
          for (Node x : cur.adj()) // 将cur相邻节点入队
              if (x not in visited) {
                  q.push(x);
                  visited.add(x);
              }
      }
      step++;		// 更新步数
  }
  ```
  
-  基本**二分搜索**

  ```
  int binary_search(int[] nums, int target) {
      int left = 0, right = nums.length - 1; 
      while(left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1; 
          } else if(nums[mid] == target) {
              // 直接返回
              return mid;
          }
      }
      // 直接返回
      return -1;
  }
  ```

-  寻找**左、右侧边界**的二分搜索

  ```
  int left_bound(int[] nums, int target) {
      int left = 0, right = nums.length - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1;
          } else if (nums[mid] == target) {
              right = mid - 1;  // 锁定左侧边界
          }
      }
      // 检查 left 越界的情况
      if (left >= nums.length || nums[left] != target)
          return -1;
      return left;
  }
  
  int right_bound(int[] nums, int target) {
      int left = 0, right = nums.length - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1;
          } else if (nums[mid] == target) {
              left = mid + 1;  // 锁定右侧边界
          }
      }
      // 检查 right 越界的情况
      if (right < 0 || nums[right] != target)
          return -1;
      return right;
  }
  ```

- **股票买卖问题**： 「状态」、「选择」 

  ```
  for 状态1 in 状态1的所有取值：
      for 状态2 in 状态2的所有取值：
          for ...
              dp[状态1][状态2][...] = 择优(选择1，选择2...)
         
         
  dp[i][k][0 or 1]
  0 <= i <= n-1, 1 <= k <= K
  n 为天数，大 K 为最多交易数
  此问题共 n × K × 2 种状态，全部穷举就能搞定。
  for 0 <= i < n:
      for 1 <= k <= K:
          for s in {0, 1}:
              dp[i][k][s] = max(buy, sell, rest)
      
  进一步：
  base case：
  dp[-1][k][0] = dp[i][0][0] = 0
  dp[-1][k][1] = dp[i][0][1] = -infinity
  状态转移方程：
  dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
  dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
  ```

- **背包问题**：

  ```
  // 01背包  一维优化
  // 若只使用前i个物品，当背包容量为j时，有dp[i][j]种方法可以装满背包。
  #include <iostream>
  #include <algorithm>
  using namespace std;
  const int N = 1010;
  int v[N], w[N], f[N];
  int main() {
      int n, m;
      cin >> n >> m;
      for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
      for (int i = 1; i <= n; i++) {
          for (int j = m; j >= v[i]; j--) {
              f[j] = max(f[j], f[j - v[i]] + w[i]);
              // 朴素：f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
          }
      }
      cout << f[m] << endl;
  }
  
  
  // 完全背包问题 最终版
  #include <iostream>
  #include <algorithm>
  using namespace std;
  const int N = 1010;
  int v[N], w[N], f[N];
  int main() {
      int n, m;
      cin >> n >> m;
      for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
      for (int i = 1; i <= n; i++) {
          for (int j = v[i]; j <= m; j++) {
              f[j] = max(f[j], f[j - v[i]] + w[i]);
              // 朴素：f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
          }
      }
      cout << f[m] << endl;
  }
  
  // 多重背包问题 朴素做法
  #include <iostream>
  #include <algorithm>
  using namespace std;
  const int N = 110;
  int v[N], w[N], s[N];
  int f[N][N];
  int main() {
      int n, m;
      cin >> n >> m;
      for (int i = 1; i <= n; i++)
          cin >> v[i] >> w[i] >> s[i]; 
      // 三重循环
      for (int i = 1; i <= n; i++) {
          for (int j = 0; j <= m; j++) {
              for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
                  f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
              }
          }
      }
      cout << f[n][m] << endl;
      return 0;
  }
  
  // 分组背包问题
  #include <iostream>
  #include <algorithm>
  using namespace std;
  const int N = 110;
  int v[N][N], w[N][N];
  int f[N];
  int s[N];
  int n, m;
  int main() {
      cin >> n >>m ;
      for (int i = 1; i <= n; i++) {
          cin >> s[i];
          for (int j = 1; j <= s[i]; j++) {
              cin >> v[i][j] >> w[i][j];
          }
      }
      // 01背包+每组选一种
      /* 
         j逆序是因为      f[j] = max(f[j],        f[j - v[i][k]]        + w[i][k])
         等价变形是    f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i][k]] + w[i][k])
      */
      for (int i = 1; i <= n; i++) {
          for (int j = m; j >= 0; j--) {
              for (int k = 1; k <= s[i]; k++) {
                  if (j >= v[i][k])
                      f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
              }
          }
      }
      cout << f[m] << endl;
      return 0;
  }
  ```

  

## Python语法糖

------



- `str[::-1]`：取从后向前（相反）的元素

- `str[len(str)-1::-1]`： 取从下标为`len(str)-1`的元素翻转读取

- `range(len-1,-1,-1)`：逆序
  `(start,end,step)`：起始位置（默认0）；结束位置；步长（默认1）

-  Python中表示正负无穷：`float("inf")`, `float("-inf")`
  
- `zip()`：把可迭代对象作为参数，将对象中对应的元素打包成一个个元组，返回这些元组组成的列表。

  ```python
  str = ['a', 'b', 'c', 'd', 'e','f']
  print(zip(str[:-1], str[1:]))
  
  [('a', 'b'), ('b', 'c'), ('c', 'd'), ('d', 'e'), ('e', 'f')]
  
  nums = ['flower','flow','flight']
  for i in zip(*nums):
      print(i)
  
  ('f', 'f', 'f')
  ('l', 'l', 'l')
  ('o', 'o', 'i')
  ('w', 'w', 'g')
  ```

- `sorted(iterable, cmp=None, key=None, reverse=False)`

  - iterable -- 可迭代对象
  - cmp -- 比较的函数
  - key -- 主要是用来进行比较的元素，只有一个参数
  - reverse -- reverse = False 升序（默认）
  - `sort()`是应用在`list`上的方法，`sorted()`可以对所有可迭代的对象进行排序操作。
  - `list`的`sort()`是对已经存在的列表进行操作，无返回值；而内建函数`sorted()`方法返回的是一个新的`list`，不是在原来的基础上进行的操作。

## C++:

------



- C++11引入了**nullptr**关键字，不同于**NULL**这个宏定义。在C++中NULL直接定义为`0`，而在C里，NULL定义为`(void*)0`，因为C语言可以隐式转换，而C++却是需要显示的写出类型转换。于是带来一个问题，一个int类型变量在函数重载时，必定会出现非预期的结果。
  - `func(NULL) --> int`; `func(nullptr) --> char *`。
- `#include<queue>`：
  - push()、pop()、size()、empty()、front()、back()
- `#include <unordered_map>`：
  - unordered_map<int, int> record;
  - record[key] = value;
  - record.find(key) != record.end();
- `string.substr(pos, n)`：pos默认值0，n默认值s.size() - pos
  - `s.substr(1))`： 取子串，依次去掉字符串首字符
- `lower_bound()`、`upper_bound()`都是利用二分查找的方法在一个排好序的数组中进行查找。
  - `lower_bound(begin, end, num)`：从数组的begin位置到end-1位置二分查找第一个大于或等于`num`的数字，找到返回该数字的地址，不存在则返回`end`。通过返回的地址减去起始地址`begin`，得到找到数字在数组中的下标。
- `map`和`set`的底层实现为平衡二叉树，`unordered_map`和`unordered_set`的底层实现为哈希表。
- 相比于C++98标准，C++11整型的最大改变就是多了**long long**。分为两种：**long long**和**unsigned long long**。在`C++11`中，标准要求long long整型可以在不同平台上有不同的长度，但至少有`64位`。与long long整型相关的一共有3个：`LONG_MIN`、`LONG_MAX`、`ULONG_MAX`。分别代表平台上最小的long long值、最大的long long 值，以及最大的 unsigned long long值。

