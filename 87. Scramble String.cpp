//搜索树，加入了剪枝
//首先是bitmap要一致
//然后如果相等直接跳下一环。
class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 != len2)
            return false;
        if(s1 == s2)
            return true;
        int bitmap[26] = {0};
        for(int i = 0; i < len1; i++)
        {
            bitmap[s1[i] - 'a']++;
            bitmap[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(bitmap[i])
                return false;
        for(int i = 1; i < len1; i++)
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))
            || isScramble(s1.substr(0, i), s2.substr(len2 - i)) && isScramble(s1.substr(i), s2.substr(0, len2 - i)))
                return true;
        return false;
    }
};