//dp[i][j]: 到(i,j)时最少需要的血量
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        dp[M][N - 1] = 1;
        dp[M - 1][N] = 1;
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};