/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval &i1, Interval &i2)
    {
        return i1.start < i2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int e = INT_MIN;
        for(int i = 0; i < len; i++)
        {
            if(intervals[i].start < e)
                return false;
            else
                e = intervals[i].end;
        }
        return true;
    }
};