//hash题，重要的是把每一个字符串都子母序排好，这样就不会存在问题。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        int len = strs.size();

        for(int i = 0; i < len; i++)
        {
            string ss = strs[i];
            sort(ss.begin(), ss.end());
            m[ss].push_back(strs[i]);
        }
        for(auto it : m)
            ret.push_back(it.second);
        return ret;
    }
};