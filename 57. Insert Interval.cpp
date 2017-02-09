/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//和上一题的思路大致类似
class Solution {
public:
    static bool comp(Interval &i1, Interval &i2)
    {
        if(i1.start == i2.start)
            return i1.end > i2.end;
        else
            return i1.start < i2.start;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        vector<Interval> ret;
        int len = intervals.size();    
        sort(intervals.begin(), intervals.end(), comp);
        
        
        int idx = 0;
        int b = newInterval.start;
        int e = newInterval.end;
        
        while(idx < len && intervals[idx].end < b)
        {
            ret.push_back(intervals[idx]);
            idx++;
        }
        if(idx == len)
        {
            ret.push_back(newInterval);
            return ret;
        }
        
        b = min(b, intervals[idx].start);
        while(idx < len && intervals[idx].start <= e)
        {
            e = max(e, intervals[idx].end);
            idx++;
        }
        ret.push_back(Interval(b, e));
        while(idx < len)
            ret.push_back(intervals[idx++]);
        return ret;
    }
};