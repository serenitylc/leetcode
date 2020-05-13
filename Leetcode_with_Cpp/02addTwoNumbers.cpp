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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode vHead(0), *p = &vHead;
        int flag = 0;  // flag 保存进位 
        while (l1 || l2 || flag) {
            int tmp = 0;
            if (l1 != nullptr) tmp += l1->val;
            if (l2 != nullptr) tmp += l2->val;
            tmp += flag;

            flag = tmp / 10;
            tmp %= 10; 

            // 利用已有节点构成新链条 破坏了原链表结构 节约了空间
            ListNode *next = l1 ? l1 : l2;
            if (next == nullptr) next = new ListNode(tmp); 
            // ListNode *next = new ListNode(tmp);
            next->val = tmp;
            
            p->next = next;
            p = p->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return vHead.next;
    }
};