//动态规划，每一次算一个位置上能不能划分s
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int len = s.size();
        vector<bool> dp(len + 1, false);
        
        dp[0] = true;
        for(int i = 1; i <= len; i++)
            for(int j = 0; j < i; j++)
                dp[i] = dp[i] || dp[j] && dict.count(s.substr(j, i - j));
        return dp[len];
    }
};