class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) 
    {
        capa = size;
        last = 0;
    }
    
    double next(int val)
    {
        if(dq.size() < capa)
        {
            dq.push_back(val);
            last += val;
            return (double)last / (double)dq.size();
        }
        else
        {
            last -= dq.front();
            dq.pop_front();
            dq.push_back(val);
            last += val;
            return (double)last / (double)capa;
        }
    }
private:
    deque<int> dq;
    int capa;
    int64_t last;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */