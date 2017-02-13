//这道题以i为轴，刚开始每一个字母都不是一组，所以初始化的时候为i - 1
//然后每一次以i为偶数和奇数轴，看一下能否使得后边界的cut值变小。
class Solution {
public:
    int minCut(string s)
    {
        int len = s.size();
        if(len == 0)
            return 0;
        vector<int> cut(len + 1, 0);
        
        for(int i = 0; i <= len; i++)
            cut[i] = i - 1;
        
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; j++)//以字母为轴
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j] + 1);
            for(int j = 1; i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j]; j++)//以空气为轴
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j + 1] + 1);
        }
        
        return cut[len];
    }
};