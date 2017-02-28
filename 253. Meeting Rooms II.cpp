/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//和算法书上学的一样，每次找最早结束的那个区间，可以得到最多参加的会议
//对应的，也就是最少的会议室数量
struct cmpque
{
    bool operator() (Interval &i1, Interval &i2)
    {
        return i1.end > i2.end;
    }
};

class Solution {
public:
    
    static bool cmpsort(Interval &i1, Interval &i2)
    {
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        int len = intervals.size();
        if(!len)
            return 0;
        priority_queue<Interval, vector<Interval>, cmpque> pque;
        sort(intervals.begin(), intervals.end(), cmpsort);
        pque.push(intervals[0]);
        for(int i = 1; i < len; i++)
        {
            if(intervals[i].start >= pque.top().end)
            {
                Interval ii(pque.top().start, intervals[i].end);
                pque.pop();
                pque.push(ii);
            }
            else
            {
                pque.push(intervals[i]);
            }
        }
        return pque.size();
    }
};