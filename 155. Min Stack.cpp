//思想是，最小值的单线条时代更迭的，所以说，只需要在存最小值的时候，多存上一个最小值即可。
//这样充分利用了一个栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        mini = INT_MAX; 
    }
    
    void push(int x) {
        if (x <= mini) {
            st.push(mini);
            mini = x;
        }
        st.push(x);
    }
    
    void pop() {
        if(st.top() == mini) {
            st.pop();
            mini = st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top()
    {
        return st.top();
    }
    
    int getMin() 
    {
        return mini;
    }
private:
    stack<int> st;
    int mini;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */