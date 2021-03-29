/* 找出两个链表的公共节点：
 * 分别把两个链表的结点放入两个栈里，这样两个链表的尾结点就位于两个栈的栈顶，接下来比较两个栈顶的结点是否相同。
 * 如果相同，则把栈顶弹出接着比较下一个栈顶，直到找到最后一个相同的结点。
 *
 * 首先遍历两个链表得到它们的长度，就能知道哪个链表比较长，以及长的链表比短的链表多几个结点。
 * 在第二次遍历的时候，在较长的链表上先走若干步，接着再同时在两个链表上遍历，找到的第一个相同的结点就是它们的第一个公共结点。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {  // 使 pa pb 走过相同长度的距离, 直到相交
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;
        }
        return pa;  // 找到两个单链表相交的起始节点
    }
};

// 用递归和非递归方法反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

class Solution {
public:
    ListNode* lastNode;
    ListNode* reverseN(ListNode* head, int n) {
        if (1 == n) {
            lastNode = head->next;
            return head;
        }
        ListNode* node = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = lastNode;
        return node;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
};

// 链表中的节点每K个一组翻转
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = reverseKGroup(next, k);
        return pre;
    }
};

// 翻转链表的每2个元素：例如 1,2,3,4,5 变成2,1,4,3,5
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dHead = new ListNode(0);
        dHead->next = head;
        ListNode* p = dHead;
        while (p->next && p->next->next) {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }
        ListNode* resNode = dHead->next;
        delete dHead;
        return resNode;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (p && q) {
            if (q->val > p->val) {
                cur->next = p;
                cur = cur->next;
                p = p->next;
            } else {
                cur->next = q;
                cur = cur->next;
                q = q->next;
            }
        }
        if (q) cur->next = q;
        if (p) cur->next = p;
        return res->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = mergeTwoLists(p1->next, p2);
            return p1;
        } else {
            p2->next = mergeTwoLists(p1, p2->next);
            return p2;
        }
    }
};

// 请判断一个链表是否为回文链表。
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *pre = NULL, *fast = head;
        while (fast && fast->next) {  // fast确保slow走到链表中间
            ListNode* temp = slow;
            slow = slow->next;
            fast = fast->next->next;
            temp->next = pre;
            pre = temp;
        }
        if (fast) slow = slow->next;  // 链表元素个数为奇数, 跳过最中间元素
        while (pre && slow) {
            if (pre->val != slow->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;  // 判断一个链表是否为回文链表 (逆序链表前半部分)
    }
};

// 合并两个有序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    /* 建立优先队列，不需要全部元素一次性入队；只需让链表头元素入队即可，弹出该元素后，该链表往后移。*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for (ListNode* list : lists) {
            if (list) q.push(list);
        }
        ListNode *head = new ListNode(0), *cur = head;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return head->next;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            if (lists[i]) head = merge(head, lists[i]);
        }
        return head;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};