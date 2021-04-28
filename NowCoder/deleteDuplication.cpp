/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead || !pHead->next) return pHead;
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        while (next) {
            if (cur->val != next->val) {
                pre = cur;
                cur = next;
                next = next->next;
            } else {
                while (next && next->val == cur->val) {
                    next = next->next;
                }
                if (pre) pre->next = next;
                else pHead = next;
                while (cur != next) {
                    ListNode* del = cur;
                    cur = cur->next;
                    free(del);
                }
                if (next) next = next->next;
            }
        }
        return pHead;
    }
};