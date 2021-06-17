/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } else {
            int tmp = head->val;
            while (head->val == tmp) {
                head = head->next;
                if (!head) return NULL;
            }
            return deleteDuplicates(head);
        }
    }
};
