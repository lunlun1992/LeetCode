//这道题的思路是滑动窗口法
//注意，这里的i可以马上到j下一个重复位置。不需要step by step
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        int ret = 0;
        for(int i = 0, j = 0; j < len; j++)
        {
            if(m.count(s[j]))
                i = max(i, m[s[j]]);
            //cout << i << "," << j << endl;
            ret = max(ret, j - i + 1);
            m[s[j]] = j + 1;
        }
        return ret;
    }
private:
    unordered_map<char, int> m;
};