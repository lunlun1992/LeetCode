class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int bs[26] = {0};
        int bt[26] = {0};
        int len = s.size();
        if(len != t.size())
            return false;
        for(int i = 0; i < len; i++)
        {
            bs[s[i] - 'a']++;
            bt[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
            if(bs[i] != bt[i])
                return false;
        return true;
    }
};