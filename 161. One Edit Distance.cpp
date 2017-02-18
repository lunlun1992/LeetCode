//编辑距离为1
//要不然两者一样长，但是差一个字母
//要不然不一样长，但是短的插入长的对应字母，就一样了
class Solution {
public:
    bool isOneEditDistance(string s, string t) 
    {
        int m = s.length();
        int n = t.length();
        if (m > n) 
            return isOneEditDistance(t, s);
        if (n - m > 1) 
            return false;
        bool mismatch = false;
        for (int i = 0; i < m; i++) 
        {
            if (s[i] != t[i]) 
            {
                if (m == n) 
                    s[i] = t[i];
                else 
                    s.insert(i, 1, t[i]);
                mismatch = true; 
                break;
            }
        }
        return (!mismatch && n - m == 1) || (mismatch && s == t);
    }
};