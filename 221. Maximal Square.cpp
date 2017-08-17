class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxi = max(maxi, dp[i][0]);
        }
        for (int j = 0; j < col; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            maxi = max(maxi, dp[0][j]);
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi * maxi;
    }
};