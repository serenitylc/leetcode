/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (!head) return res;
        res = printListFromTailToHead(head->next);
        res.push_back(head->val);
        return res;
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp = cur;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        vector<int> res;
        while (pre) {
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};