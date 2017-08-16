//判断首个字符是不是一样，如果是一样就都去掉，然后比剩下的那些。
//如果收个字符不一样，则去掉i的首字符，再比较。
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if(slen < tlen)
            return 0;
        
        vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1, 0));
        for (int i = 0; i <= slen; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= slen; i++) {
            for (int j = 1; j <= i && j <= tlen; j++) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] += s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0;
            }
        }
        return dp[slen][tlen];
    }
};