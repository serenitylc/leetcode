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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = slow->next;
        slow->next = nullptr;
        ListNode* newHead = reverseList(p);
        while (head && newHead) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = newHead->next;
            head->next = newHead;
            newHead->next = tmp1;
            head = tmp1;
            newHead = tmp2;
            
        }
        return;
    }
};