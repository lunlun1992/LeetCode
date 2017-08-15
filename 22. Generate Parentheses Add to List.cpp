//DFS, every tree node has two numbers
//left num and right num
//indicates the left parenthese num and right parenthese num.
class Solution {
public:    
    void dfs(int n, int l, int r, vector<string>& ret, string now) {
        if (l == n && r == n) {
            ret.push_back(now);
            return;
        } else if(l > n || r > l) {
            return;
        }
        
        now.push_back('(');
        dfs(n, l + 1, r, ret, now);
        now.pop_back();
        
        now.push_back(')');
        dfs(n, l, r + 1, ret, now);
        now.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string now = "";
        dfs(n, 0, 0, ret, now);
        return ret;
    }
};