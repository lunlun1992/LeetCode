//这道题以i为轴，刚开始每一个字母都不是一组，所以初始化的时候为i - 1
//然后每一次以i为偶数和奇数轴，看一下能否使得后边界的cut值变小。
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len + 1, 0);
        
        for (int i = 0; i <= len; i++)  //当i为0的时候，切割次数是－1，原因是当找到0时，切割次数加一，此时并不需要切割
            dp[i] = i - 1;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; j++) {   // 以i为轴
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j]);
            }
            
            for (int j = 1; i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j]; j++) {   //以i右边的空气为轴
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j + 1]);
            }
        }
        return dp[len];
    }
};