只能用栈的操作模仿队列，用一个辅助栈即可。
import java.util.Stack;

class MyQueue {
     Stack<Integer> stack = new Stack<Integer>();
    // Push element x to the back of queue.
    public void push(int x)
    {
     stack.push(x);
    }

    // Removes the element from in front of queue.
    public void pop()
    {
     if(stack.isEmpty())
            return;
     else
     {
           Stack<Integer> tmp = new Stack<Integer>();
            while(! stack.isEmpty())
           {
                tmp.push( stack.pop());
           }
           tmp.pop();
            while(!tmp.isEmpty())
           {
                 stack.push(tmp.pop());
           }               
     }
    }

    // Get the front element.
    public int peek()
    {
     if(stack.isEmpty())
            return 0;
     else
     {
           Stack<Integer> tmp = new Stack<Integer>();
            while(! stack.isEmpty())
           {
                tmp.push( stack.pop());
           }
            int t = tmp.pop();
            while(!tmp.isEmpty())
           {
                 stack.push(tmp.pop());
           }  
            return t;
     }
    }

    // Return whether the queue is empty.
    public boolean empty()
    {
     return stack.isEmpty();
    }
}