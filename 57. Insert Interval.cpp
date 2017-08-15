/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//Just like the previous question
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        int len = intervals.size();
        vector<Interval> ret;
        while (i < len && intervals[i].end < newInterval.start)
            ret.push_back(intervals[i++]);
        if (i == len) {
            ret.push_back(newInterval);
            return ret;
        }
        int e = newInterval.end;
        int s = min(intervals[i].start, newInterval.start);
        while (i < len && e >= intervals[i].start) {
            e = max(e, intervals[i++].end);
        }
        ret.emplace_back(s, e);
        while (i < len)
            ret.push_back(intervals[i++]);
        return ret;
    }
};