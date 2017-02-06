/*dp方式十分复杂，其主要思路如下：
f(i,j)代表字符串第i个和模式第j个之前是否都匹配。
如果当前模式位置上的不是*，就正常匹配即可。
如果是*
1、有可能是*匹配空串，则f(i,j-2)
2、有可能是*匹配多个字符，则在这个条件下看f(i-1,j)即可。*/

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
        
        dp[0][0] = true;
        for (int j = 1; j <= lenp; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        
        for (int i = 1; i <= lens; i++)
            for (int j = 1; j <= lenp; j++)
                if (p[j - 1] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];


        return dp[lens][lenp];
    }
};