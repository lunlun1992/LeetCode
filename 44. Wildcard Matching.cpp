//和第十题一样的类型，动态规划
//完全匹配作为一种情况
//通配符作为另外两种情况，分别是空串以及适配1-多字符的情况
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
        
        dp[0][0] = true;
        for(int j = 1; j <= lenp; j++)
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
        
        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if ('*' != p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?');
                else
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
        return dp[lens][lenp];
    }
};