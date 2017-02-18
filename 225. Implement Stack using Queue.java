//只能用栈的操作模拟队列。push方便，pop的时候要利用一个辅助队列将出队的东西存下来，扔掉最后一个，再重新入队。
import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    // Push element x onto stack.
     LinkedList<Integer> que = new LinkedList<Integer>();
    public void push(int x)
    {
         que.add(x);
    }

    // Removes the element on top of the stack.
    public void pop()
    {
        if(que.isEmpty())
             return;
        else
             que.pollLast();
    }

    // Get the top element.
    public int top()
    {
         if(que.isEmpty())
              return 0;
         else
              return que.peekLast();
    }

    // Return whether the stack is empty.
    public boolean empty()
    {
         return que.isEmpty();
    }
}