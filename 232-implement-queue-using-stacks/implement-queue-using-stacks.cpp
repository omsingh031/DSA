class MyQueue {
private:
    stack<int> inStack, outStack;
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    MyQueue() {}
    void push(int x) {
        inStack.push(x);
    }
    int pop() {
        if (outStack.empty()) {
            transfer();
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }
    int peek() {
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */