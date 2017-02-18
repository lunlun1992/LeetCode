class Solution {
public:
#define MAX(a,b) (a) > (b) ? (a) : (b)
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int height = matrix.size();
        int width = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp;
        
        for(int i = 0; i < height; i++)
        {
            vector<int> vec(width, 0);
            dp.push_back(vec);
        }
        for(int i = 0; i < height; i++)
        {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            if(!maxi)
                maxi = matrix[i][0] == '1' ? 1 : 0;
        }
        for(int j = 1; j < width; j++)
        {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            if(!maxi)
                maxi = matrix[0][j] == '1' ? 1 : 0;
        }
        
        for(int i = 1; i < height; i++)
        {      
            for(int j = 1; j < width; j++)
            {
                if(dp[i - 1][j - 1] && matrix[i][j] == '1')
                {
                    int len = dp[i - 1][j - 1];
                    int k = 1;
                    for(; j - k >= 0 && i - k >= 0; k++)
                        if(matrix[i][j - k] == '0' || matrix[i - k][j] == '0')
                            break;
                    if(k > len)
                        dp[i][j] = len + 1;
                    else
                        dp[i][j] = k;
                }
                else
                {
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                maxi = MAX(maxi, dp[i][j]);
            }
        }
        return maxi * maxi;
    }
};