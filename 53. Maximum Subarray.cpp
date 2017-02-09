//dp[i - 1] >= nums[0] + ... + nums[i - 1]
//dp[i - 1] >= nums[1] + ... + nums[i - 1]
//....
//dp[i - 1] >= nums[i - 1];

//dp[i - 1] + nums[i] >= nums[0] + ... + nums[i - 1] + nums[i]
//dp[i - 1] + nums[i] >= nums[1] + ... + nums[i - 1] + nums[i]
//...
//dp[i - 1] + nums[i] >= nums[i - 1] + nums[i]
//dp[i] = max(dp[i - 1] + nums[i], nums[i])满足条件
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        if(!len)
            return 0;
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int ret = dp[0];
        for(int i = 1; i < len; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(dp[i], ret);
        }
        return ret;
    }
};