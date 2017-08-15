//BFS形式，最好的方法就是确定本次的区间，然后在本次的区间之内找到下一次最远的距离，则下一个区间就在mini+1到maxi之间。
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = 0;
        int ret = 0;
        while(end < len - 1) {
            ret++;
            int maxend = end;
            for(int i = start; i <= end; i++)
                maxend = max(maxend, i + nums[i]);  
            start = end + 1;
            end = maxend;
        }
        return ret;
    }
};