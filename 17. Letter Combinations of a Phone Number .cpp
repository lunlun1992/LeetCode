//DFS
class Solution {
public:
    const string tele[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(string digits, int idx, vector<string>& ret, string& now) {
        if(idx == digits.size()) {
            ret.push_back(now);
            return;
        }
        int di = digits[idx] - '0';
        for (int i = 0; i < tele[di].size(); i++) {
            now.push_back(tele[di][i]);
            dfs(digits, idx + 1, ret, now);
            now.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return {};
        string now = "";
        dfs(digits, 0, ret, now);
        return ret;
    }
};