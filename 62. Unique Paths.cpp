//dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + n - 1, vector<int>(m, 0));
        for (int i = 0; i <= m + n - 2; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= m + n - 2; i++) {
            for (int j = 1; j <= m - 1; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp[m + n - 2][m - 1];
    }
};