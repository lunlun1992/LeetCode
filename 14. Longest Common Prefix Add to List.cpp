//Greedy check all the strings and find the common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int ret = strs[0].size();
        for (auto s : strs) {
            int j = 0;
            while (j < ret && strs[0][j] == s[j]) j++;
            ret = j;
        }
        return strs[0].substr(0, ret);
    }
};