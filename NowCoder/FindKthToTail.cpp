/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || k <= 0) return nullptr;
        ListNode *p = pHead, *q = pHead;
        while (p && k) {
            --k;
            p = p->next;
        }
        if (k) return nullptr;
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};