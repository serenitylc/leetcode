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
