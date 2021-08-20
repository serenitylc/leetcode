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
        if (mid == target) {
			return nums[mid];
		} else if (mid < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
    }
    return nums[l];
}

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        return quick_sort(a, 0, n-1, n, K);
    }
    int quick_sort(vector<int>& a, int start, int end, int n, int k) {
        int base = a[start];
        int i = start;
        int j = end;
        int res = 0;
        while (i < j) {
            while (i < j && a[j] >= base) --j;
            while (i < j && a[i] <= base) ++i;
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[start], a[j]);
        if (n - j == k) {
			return a[j];
		} else if (n - j < k) {
			res = quick_sort(a, start, j-1, n, k);
		} else if (n - j > k) {
			res = quick_sort(a, j+1, end, n, k);
		}
        return res;
    }
};
// 维护 K 个元素的最小堆
class Solution {
public:
    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    int findKth(vector<int> a, int n, int K) {
        priority_queue<int, vector<int>, compare> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(a[i]);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// 二叉搜索树的第k大节点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> inorder;
        InOrder(root, inorder);
        return inorder[inorder.size() - k];
    }
    void InOrder(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        InOrder(root->left, inorder);
        inorder.push_back(root->val);
        InOrder(root->right, inorder);
    }
};

class Solution {
private:
    unordered_map<TreeNode*, int> childNum;
public:
    int kthLargest(TreeNode* root, int k) {
        if (!root) return -1;
        int r_num = numsOfChild(root->right);
        if (r_num + 1 == k) {
			return root->val;
		} else if (r_num + 1 < k) {
			return kthLargest(root->left, k - r_num - 1);
		} else {
			return kthLargest(root->right, k);
		}
    }
    int numsOfChild(TreeNode* root) {
        if (!root) return 0;
        if (childNum.find(root) != childNum.end()) {
			return childNum[root];
		}
        childNum[root] = 1 + numsOfChild(root->left) + numsOfChild(root->right);
        return childNum[root];
    }
};

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
		if (q >= r || (p < m && nums[p] <= nums[q])) {
			temp[index++] = nums[p++];
		} else {
			temp[index++] = nums[q++];
		}
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
		for (int j = 1; j < n - i + 1; ++j) {
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
	int index;
	for (int i = 0; i < n - 1; ++i) {
		index = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[index])
				index = j;
		}
		swap(nums[index], nums[i]);
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

/* 堆（完全二叉树）的实现 */
vector<int> heap;
// 获取最大值
void top() {
	return heap[0];
}
// 插入任意值：把该值放到最后一位，然后上浮
void push(int k) {
	heap.push_back(k);
	swim(heap.size() - 1);
}
// 删除最大值：把最后一位移到前面，然后下沉
void pop() {
	heap[0] = heap.back();
	heap.pop_back();
	sink(0);
}
// 上浮
void swim(int pos) {
	while (pos >= 1 && heap[pos/2] < heap[pos]) {
		swap(heap[pos/2], heap[pos]);
		pos /= 2;
	}
}
// 下沉
void sink(int pos) {
	while (2 * pos <= N) {
		int i = 2 * pos;
		if (i < N && heap[i] < heap[i+1]) ++i;
		if (heap[pos] >= heap[i]) break;
		swap(heap[pos], heap[i]);
		pos = i;
	}
}

// 堆排序
void HeapSort(vector<int>& nums, int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		adjust(nums, size, i);
	}
	for (int i = size - 1; i >= 1; i--) {
		swap(nums[0], nums[i]);        
		adjust(nums, i, 0);              
	}
}
void adjust(vector<int>& nums, int len, int index) {
	int left = 2*index + 1;   // index左子节点
	int right = 2*index + 2;  // index右子节点
	int maxIdx = index;
	if (left < len && nums[left] > nums[maxIdx]) {
		maxIdx = left;
	}
	if (right < len && nums[right] > nums[maxIdx]) {
		maxIdx = right;
	}
	if (maxIdx != index) {
		swap(nums[maxIdx], nums[index]);
		adjust(nums, len, maxIdx);
	}
}