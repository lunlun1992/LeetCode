class Solution {
public:
    int rob(vector<int>& nums)
    {
        int ret = INT_MIN;
        int len = nums.size();
        if(!len)
            return 0;
        else if(1 == len)
            return nums[0];
        vector<int> dp(len + 1, 0);
        //不抢最后一家
        dp[1] = nums[0];
        for(int i = 2; i < len; i++)
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        ret = max(ret, dp[len - 1]);
        
        //不抢第一家
        dp[1] = 0;
        for(int i = 2; i <= len; i++)
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        ret = max(ret, dp[len]);
        return ret;
    }
};