//BFS形式，最好的方法就是确定本次的区间，然后在本次的区间之内找到下一次最远的距离，则下一个区间就在mini+1到maxi之间。
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 2)
            return 0;
        int counts = 0;
        int mini = 0;
        int maxi = 0;
        while(maxi < len - 1)
        {
            int temp = maxi;
            for(int i = mini; i <= temp; i++)
            {
                maxi = max(maxi, i + nums[i]);
            }
            mini++;
            counts++;
        }
        return counts;
    }
};