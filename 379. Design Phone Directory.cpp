class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxnums = maxNumbers;
        for(int i = 0; i < maxNumbers; i++)
            avai.push(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() 
    {
        if(avai.empty())
            return -1;
        int ret = avai.front();
        used.insert(ret);
        avai.pop();
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number >= maxnums || number < 0)
            return false;
        return !used.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) 
    {
        if(used.count(number))
        {
            used.erase(number);
            avai.push(number);
        }
    }
private:
    int maxnums;
    unordered_set<int> used;
    queue<int> avai;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */