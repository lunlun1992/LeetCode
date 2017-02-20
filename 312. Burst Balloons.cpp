//算法书上典型的二维动态规划题目，dp[i][j]代表i到j为边界的气球族的最大值，其不用担心边界会变化。
//为了不采用递归的方法加入多余计算，所以采用从最小长度到最大长度的dp方法进行计算，其时间复杂度为O(n^3)
class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int len = nums.size();
        vector<vector<int>> dp;
        for(int i = 0; i < len; i++)
        {
            vector<int> temp(len, 0);
            dp.push_back(temp);
        }

        for(int l = 1; l < len; l++)//gap length between low boundary and high boundary
        {
            for(int lowb = 0; lowb < len - l; lowb++)
            {
                int highb = lowb + l;
                for(int k = lowb + 1; k < highb; k++)
                    dp[lowb][highb] = max(dp[lowb][highb], nums[lowb] * nums[highb] * nums[k] + dp[lowb][k] + dp[k][highb]);
            }
        }
        return dp[0][len - 1];
    }
};