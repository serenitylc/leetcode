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