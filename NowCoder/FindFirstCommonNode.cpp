/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return nullptr;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1 != p2) {
            p1 = (p1 == NULL ? pHead2 : p1->next);
            p2 = (p2 == NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};