class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        if not intervals:
            return 0
        intervals = sorted(intervals, key = lambda x: x[1])  # 根据区间右端点排序
        res = 0
        new_interval = intervals[0]     # 被选的最新区间
        for interval in intervals[1:]:
            if interval[0] < new_interval[1]:   # 重叠则删除区间
                res += 1
            else:  # 不重叠则更新new_interval
                new_interval = interval
        return res

# sorted(iterable, cmp=None, key=None, reverse=False)
# iterable -- 可迭代对象
# cmp -- 比较的函数
# key -- 主要是用来进行比较的元素，只有一个参数
# reverse -- reverse = False 升序（默认）

# sort()是应用在 list 上的方法，sorted()可以对所有可迭代的对象进行排序操作。
# list 的sort()是对已经存在的列表进行操作，无返回值; 
# 而内建函数sorted()方法返回的是一个新的 list，不是在原来的基础上进行的操作。