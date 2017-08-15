//滑动窗口法，其大致思路是：
//1. 找到e的边界，获得最大值
//2. 缩减b，直到e的边界松开。
//3. 每次需要维护的状态是：b在序列里面，e不在序列里面。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int has[256];
        memset(has, 0, sizeof(has));
        int b = 0;
        int e = 0;
        int len = s.size();
        int ret = 0;
        while(e < len) {
            while(e < len && has[s[e]] == 0) ++has[s[e++]];
            ret = max(ret, e - b);
            if(e >= len)
                break;
            while(b < e && has[s[e]] == 1) --has[s[b++]];
        }
        return ret;
    }
};