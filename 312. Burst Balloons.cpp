//算法书上典型的二维动态规划题目，dp[i][j]代表i到j为边界的气球族的最大值，其不用担心边界会变化。
//为了不采用递归的方法加入多余计算，所以采用从最小长度到最大长度的dp方法进行计算，其时间复杂度为O(n^3)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int d = 2; d < len; d++) {
            for (int i = 0; i + d < len; i++) {
                int j = i + d;
                for (int k = i + 1; k < j; k++) {   
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return dp[0][len - 1];
    }
};