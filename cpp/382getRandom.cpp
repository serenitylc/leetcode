/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if (!head) return -1;
        ListNode* p = head;
        int res = p->val;  // 蓄水池抽样算法, 水池大小为1, 定义一个常量
        p = p->next;
        int index = 1;
        while (p != NULL) {
            index++;
            int randomNum = rand() % index;  // 生成 [0...index-1] 的随机数
            if (randomNum == 0) res = p->val;  // 替换水池中的元素
            p = p->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */