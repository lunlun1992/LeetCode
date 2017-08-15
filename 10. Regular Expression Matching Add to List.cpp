/*dp方式十分复杂，其主要思路如下：
f(i,j)代表字符串第i个和模式第j个之前是否都匹配。
如果当前模式位置上的不是*，就正常匹配即可。
如果是*
1、有可能是*匹配空串，则f(i,j-2)
2、有可能是*匹配多个字符，则在这个条件下看f(i-1,j)即可。*/

class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if('*' != p[j - 1])
                    dp[i][j] = (p[j - 1] == s[i - 1] || '.' == p[j - 1]) && dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];   
            }
        }
        return dp[m][n];
    }
};