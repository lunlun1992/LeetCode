//dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if(m == n && n == 1)
            return 1;
        int length = m - 1 + n - 1;
        if(m < n)
        {
            vector<vector<int>> dp(length + 1, vector<int>(m, 0));
            dp[1][0] = dp[1][1] = 1;
            for(int i = 2; i <= length; i++)
            {
                dp[i][0] = 1;
                for(int j = 1; j <= m - 1; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            return dp[length][m - 1];
        }
        else
        {
            vector<vector<int>> dp(length + 1, vector<int>(n, 0));
            dp[1][0] = dp[1][1] = 1;
            for(int i = 2; i <= length; i++)
            {
                dp[i][0] = 1;
                for(int j = 1; j <= n - 1; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            return dp[length][n - 1];
        }
        
    }
};