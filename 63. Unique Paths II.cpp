//只能从上面或者左边到达，否则不是唯一道路。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 1; i < m; i++) 
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j - 1];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};