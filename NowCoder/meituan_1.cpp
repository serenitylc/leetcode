#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newH = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newH;
}

void test() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    ListNode* res = reverseList(head);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    return;
}

int main() {
    test();
    return 0;
}

// mvcc 平衡二叉树的调整  http 307    tls  thread local  滑动窗口   虚拟地址的上限