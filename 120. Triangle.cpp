//记忆华搜索
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int row = triangle.size();
        if(!row)
            return 0;
        int col = triangle[0].size();
        int dp[row][row];
        for(int j = 0; j < row; j++)
            dp[row - 1][j] = triangle[row - 1][j];
        
        for(int i = row - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        return dp[0][0];
    }
};