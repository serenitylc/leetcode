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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) {
            ListNode* delNode = head;
            head = delNode->next;
            delete delNode;
        }

        if(head == NULL)
            return NULL;

        ListNode* cur = head;
        while(cur->next) {
            if(cur->next->val == val) {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dHead = new ListNode(0);
        dHead->next = head;
        ListNode* cur = dHead;
        while(cur->next) {
            if(cur->next->val == val) {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        return dHead->next;
    }
};