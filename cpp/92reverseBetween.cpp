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