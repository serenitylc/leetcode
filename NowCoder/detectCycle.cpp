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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            if (!fast || !fast->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};