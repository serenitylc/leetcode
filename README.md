## Leetcode

- `动态规划`的核心问题是穷举，由于这类问题存在「重叠子问题」，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程。

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


- `回溯问题`，实际上就是一个决策树的遍历过程，不合适就退回上一步，通过约束条件, 减少时间复杂度。

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


- `BFS`本质：从一个起点，走到终点，问最短路径。

  ```
  // 计算从起点 start 到终点 target 的最近距离
  int BFS(Node start, Node target) {
      queue<Node> q; 		// 核心数据结构
      Set<Node> visited;  // 避免走回头路
  	q.push(start); 		// 将起点加入队列
  	visited.add(start);
  	int step = 0; 		// 记录扩散的步数
  	while (q not empty) {
      int sz = q.size();
      /* 将当前队列中的所有节点向四周扩散 */
      for (int i = 0; i < sz; i++) {
          Node cur = q.pop();
          if (cur is target)	// 判断是否到达终点
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

## Python语法糖

- `str[::-1]`：取从后向前（相反）的元素

- `str[len(str)-1::-1]`： 取从下标为`len(str)-1`的元素翻转读取

- `range(len-1,-1,-1)`：逆序
  `(start,end,step)`：起始位置（默认0）；结束位置；步长（默认1）

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

  - `iterable `-- 可迭代对象
  - `cmp` -- 比较的函数
  - `key` -- 主要是用来进行比较的元素，只有一个参数
  - `reverse` -- reverse = False 升序（默认）
  - `sort()`是应用在`list`上的方法，`sorted()`可以对所有可迭代的对象进行排序操作。
  - `list`的`sort()`是对已经存在的列表进行操作，无返回值；而内建函数`sorted()`方法返回的是一个新的`list`，不是在原来的基础上进行的操作。

## C++:

- `C++11`引入了`nullptr`关键字，不同于`NULL`这个宏定义。在`C++`中`NULL`直接定义为`0`，而在`C`里，`NULL`定义为`(void*)0`，因为C语言可以隐式转换，而C++却是需要显示的写出类型转换。于是带来一个问题，一个`int`类型变量在函数重载时，必定会出现非预期的结果。
  - `func(NULL) --> int`; `func(nullptr) --> char *`。
- `#include<queue>`：
  - `push()`、`pop()`、`size()`、`empty()`、`front()`、`back()`
- `string.substr(pos, n)`：`pos`默认值0，`n`默认值`s.size() - pos`
  - `s.substr(1))`： 取子串，依次去掉字符串首字符
- `lower_bound()`、`upper_bound()`都是利用二分查找的方法在一个排好序的数组中进行查找。
  - `lower_bound(begin, end, num)`：从数组的`begin`位置到`end-1`位置二分查找第一个大于或等于`num`的数字，找到返回该数字的地址，不存在则返回`end`。通过返回的地址减去起始地址`begin`，得到找到数字在数组中的下标。
- `map`和`set`的底层实现为平衡二叉树，`unordered_map`和`unordered_set`的底层实现为哈希表。
- 相比于`C++98`标准，`C++11`整型的最大改变就是多了` long long`。分为两种：`long long`和`unsigned long long`。在`C++11`中，标准要求`long long`整型可以在不同平台上有不同的长度，但至少有`64位`。与`long long`整型相关的一共有3个：`LONG_MIN`、`LONG_MAX`、`ULONG_MAX`。分别代表平台上最小的`long long`值、最大的`long long `值，以及最大的 `unsigned long long`值。