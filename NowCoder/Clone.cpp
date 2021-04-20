// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        unordered_map<RandomListNode*, RandomListNode*> m;
        while (p) {
            RandomListNode* newHead = new RandomListNode(p->label);
            m[p] = newHead;
            p = p->next;
        }
        p = pHead;
        while (p) {
            m[p]->next = p->next == NULL ? NULL : m[p->next];
            m[p]->random = p->random == NULL ? NULL : m[p->random];
            p = p->next;
        }
        return m[pHead];
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;
        RandomListNode* p = pHead;
        while (p) {
            RandomListNode* newNode = new RandomListNode(p->label);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        p = pHead;
        while (p) {
            p->next->random = p->random == NULL ? NULL : p->random->next;
            p = p->next->next;
        }
        p = pHead;
        RandomListNode* newHead = p->next;
        while (p) {
            RandomListNode* newNode = p->next;
            p->next = newNode->next;
            newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
            p = p->next;
        }
        return newHead;
    }
};