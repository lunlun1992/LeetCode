//hash题，重要的是把每一个字符串都子母序排好，这样就不会存在问题。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }
        
        for (auto p : m) {
            ret.push_back(p.second);
        }
        return ret;
    }
};