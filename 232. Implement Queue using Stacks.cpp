//st2是输出缓冲区
//缓冲区空时，才会从st1里面往st2里面塞数据
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        st2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1, st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */