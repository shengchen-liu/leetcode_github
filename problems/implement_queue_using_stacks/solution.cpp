/**
queue: FIFO
stack: FILO
[1]
[1, 2]   stack1: [2, 1]  stack2 : [1, 2]
[1, 2, 3] s1: [3, 2, 1]  s2: [1, 2, 3]
[1, 2]: peek() => 1
[2]

**/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) {
            front = x;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = s1.top();
        s1.pop();
        if (!s1.empty()) {
            front = s1.top();
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
private:
    stack<int> s1, s2;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */