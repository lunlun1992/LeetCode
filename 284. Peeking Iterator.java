//注意peek的逻辑要先判断队列中有没有，而且不一定要使用队列。
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer>
{
    static Queue<Integer> que;
    static Iterator<Integer> it;
     public PeekingIterator(Iterator<Integer> iterator) {
         // initialize any member here.
         que = new LinkedList<Integer>();
         it = iterator;
     }

    // Returns the next element in the iteration without advancing the iterator.
     public Integer peek() {
         if(!que.isEmpty())
             return que.peek();
         else
         {
            int n = it.next();
            que.offer(n);
            return n;
         }
     }

     // hasNext() and next() should behave the same as in the Iterator interface.
     // Override them if needed.
     @Override
     public Integer next() {
         if(!que.isEmpty())
             return que.poll();
         else
             return it.next();
     }

     @Override
     public boolean hasNext()
     {
         if(!que.isEmpty())
             return true;
         else
             return it.hasNext();  
     }
}
