//1、如果自己是0，只能祈求前面的是1或者2，否则返回0。
//2、如果自己不是0，前面的可以带上自己，dp[i] = dp[i - 1] + dp[i - 2]
//3、如果不能带上，就自己一起，dp[i] = dp[i - 1]。
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        int len = s.size();
        vector<int> dp(len + 1, 0);                     //长度 + 1
        if (s[0] == '0')
            return 0;
        dp[0] = dp[1] = 1;                              //没有以及1个数字都是一种解码方法
        
        for(int i = 2; i <= len; i++) {
            if (s[i - 1] == '0') {
                if(s[i - 2] != '1' && s[i - 2] != '2')
                    return 0;
                dp[i] = dp[i - 2];
            } else {
                if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] > '0' && s[i - 1] < '7'))
                    dp[i] = dp[i - 2] + dp[i - 1];
                else
                    dp[i] = dp[i - 1];
            }
        }
        return dp[len];
    }
};