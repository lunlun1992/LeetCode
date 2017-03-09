/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//重复加法
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        int last = 0;
        int ret = 0;
        vector<NestedInteger> nextlevel = nestedList;
        while(!nextlevel.empty())
        {
            vector<NestedInteger> now;
            int len = nextlevel.size();
            for(int i = 0; i < len; i++)
            {
                if(nextlevel[i].isInteger())
                    last += nextlevel[i].getInteger();
                else
                    now.insert(now.end(), nextlevel[i].getList().begin(), nextlevel[i].getList().end());
            }
            ret += last;
            nextlevel = now;
        }
        return ret;
    }
};