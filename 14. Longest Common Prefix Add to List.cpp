//通过维护len来维护最长prefix。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.empty())
            return "";
        int i_strs = strs.size();
        int len = strs[0].size();
        for(int i = 1; i < i_strs; i++)
        {
            len = min(len, strs[i].size());
            if(len == 0)
                return "";
            int j = 0;
            while(j < len && strs[i][j] == strs[0][j])
                j++;
            len = j;
        }
        
        return strs[0].substr(0, len);
    }
};