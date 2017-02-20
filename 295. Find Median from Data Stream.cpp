//用了两个优先队列，大顶堆用来存小值，小顶堆用来存大值。
//然后最后的返回值就是两个堆之中的平均值。
//为了考虑更少的情况，可以这样操作：
//如果长度相等，尽可能的放在大顶堆里面，存不了就把小顶堆里面的顶拿出来放过来。
//反之亦然。
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num)
    {
        int lenb = before.size();
        int lena = after.size();
        if(lenb == 0)
        {
            before.push(num);
            return;
        }
        if(lena == lenb)
        {
            if(num <= after.top())
                before.push(num);
            else
            {
                before.push(after.top());
                after.pop();
                after.push(num);
            }
        }
        else
        {
            if(num >= before.top())
                after.push(num);
            else
            {
                after.push(before.top());
                before.pop();
                before.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if(after.size() == before.size())
            return (double)((after.top() + before.top()) / 2.0);
        else
            return (double)before.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> after;
    priority_queue<int> before;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();