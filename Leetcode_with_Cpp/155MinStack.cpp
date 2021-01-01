class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (min_stack.size() == 0 || min_stack.top() >= x) {
            min_stack.push(x);
        }
        data_stack.push(x);
    }
    
    void pop() {
        if (data_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




class MinStack {
public:
    /** initialize your data structure here. */
    struct Node {
        int val;
        int min;
        Node *next;
        Node(int _val, Node *_next = NULL) : val(_val), min(val), next(_next) {}
    };
    Node *head;

    MinStack() {
        head = new Node(0);
    }
  
    void push(int x) {
        Node *tmp = new Node(x, head->next);
        if (head->next && x > head->next->min) {  // tmp->min 记录该节点之前所有节点最小值； 新建节点加到 head->next 以便 pop;
			tmp->min = head->next->min;
		}
		head->next = tmp;
    }
    
    void pop() {
        Node *tmp = head->next;
		if (tmp) {
			head->next = tmp->next;
			delete tmp;
		}
    }
    
    int top() {
        int top = 0;
		if (head->next) {
			top = head->next->val;
		}
		return top;
    }
    
    int getMin() {
        int min = 0;
		if (head->next) {
			min = head->next->min;
		}
		return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */