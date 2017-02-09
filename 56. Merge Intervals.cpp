/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//大致的思路是，先排序
//然后贪心的找终点，每一次更新一次终点
//直到找不到为止。
class Solution {
public:
    static bool comp(Interval &i1, Interval &i2)
    {
        if(i1.start == i2.start)
            return i1.end > i2.end;
        else
            return i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<Interval> ret;
        int len = intervals.size();    
        if(!len)
            return ret;
        sort(intervals.begin(), intervals.end(), comp);
        
        int idx = 0;
        while(idx < len)
        {
            int b = intervals[idx].start;
            int e = intervals[idx].end;
            cout << b << " " << e << endl;
            while(idx < len && intervals[idx].start <= e)
            {
                e = max(e, intervals[idx].end);
                //cout << b << " " << e << endl;
                idx++;
            }
            ret.push_back(Interval(b, e));

        }
        
        
        return ret;
    }
    
};