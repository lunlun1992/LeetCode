//三种情况中插入删除是等价的，最后一种替换是可以通过直接忽略两个元素而达成的
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();
        int dp[len1 + 1][len2 + 1] = {0};
        
        dp[0][0] = 0;
        for(int i = 1; i <= len1; i++)
            dp[i][0] = i;
        for(int j = 1; j <= len2; j++)
            dp[0][j] = j;
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++)
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        return dp[len1][len2];
    }
};