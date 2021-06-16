/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while (head1) {
            st1.push(head1);
            head1 = head1->next;
        }
        while (head2) {
            st2.push(head2);
            head2 = head2->next;
        }
        ListNode* res = NULL;
        int cnt = 0;
        while (cnt || st1.size() || st2.size()) {
            int a = 0, b = 0;
            if (st1.size()) {
                ListNode* temp = st1.top();
                st1.pop();
                a = temp->val;
            }
            if (st2.size()) {
                ListNode* temp = st2.top();
                st2.pop();
                b = temp->val;
            }
            int count = (a + b + cnt) % 10;
            cnt = (a + b + cnt) / 10;
            ListNode* p = new ListNode(count);
            if (res == NULL) res = p;
            else {
                p->next = res;
                res = p;
            }
        }
        return res;
    }
};