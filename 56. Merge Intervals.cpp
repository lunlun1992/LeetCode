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
    
    static bool sortfunc(Interval& i1, Interval& i2) {
        return i1.start == i2.start ?
            i1.end < i2.end : i1.start < i2.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int i = 0;
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), sortfunc);
        vector<Interval> ret;
        while (i < len) {
            int e = intervals[i].end;
            int s = intervals[i].start;
            while (i < len && e >= intervals[i].start) {
                e = max(e, intervals[i++].end);
            }
            ret.emplace_back(s, e);
        }
        return ret;
    }
};