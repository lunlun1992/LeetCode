class Solution {
public:
    vector<vector<string>> ret;
    vector<string> now;
    
    bool isP(string&s, int b, int e) {
        while (b < e) {
            if (s[b] == s[e]) {
                b++;
                e--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    void dfs(string& s, int idx) {
        if (idx == s.size()) {
            ret.push_back(now);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isP(s, idx, i)) {
                now.push_back(s.substr(idx, i - idx + 1));
                dfs(s, i + 1);
                now.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ret;
    }
};