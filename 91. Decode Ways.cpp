//1、如果自己是0，只能祈求前面的是1或者2，否则返回0。
//2、如果自己不是0，前面的可以带上自己，dp[i] = dp[i - 1] + dp[i - 2]，注意不要下溢出。
//3、如果不能带上，就自己一起，dp[i] = dp[i - 1]。
class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.empty())
            return 0;
        int len = s.size();
        vector<int> dp(len, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        
        for(int i = 1; i < len; i++)
        {
            if(s[i] == '0')
            {
                if(s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                dp[i] = i >= 2 ? dp[i - 2] : 1;
            }
            else
                if(s[i - 1] == '1')
                    dp[i] = i >= 2 ? dp[i - 2] + dp[i - 1] : dp[i - 1] + 1;//这里的+1不要漏
                else if(s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')
                    dp[i] = i >= 2 ? dp[i - 2] + dp[i - 1] : dp[i - 1] + 1;
                else
                    dp[i] = dp[i - 1];
        }
        return dp[len - 1];
    }
};