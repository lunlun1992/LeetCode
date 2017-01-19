//递归搜索
class Solution {
public:
    void dfs(int n, int now, int left, string &last, vector<string> &ret)
    {
        if(left < 0 || left > n)
            return;
        if(left == 0 && now == n * 2)
        {
            ret.push_back(last);
            return;
        }
        else if(left && now == n * 2)
        {
            return;
        }
        now++; 
        
        last += '(';
        left++;
        dfs(n, now, left, last, ret);
        last.pop_back();
        left--;
        
        last += ')';
        left--;
        dfs(n, now, left, last, ret);
        last.pop_back();
        left++;
        
        now--;
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        string last = "";
        dfs(n, 0, 0, last, ret);
        return ret;
        
    }
};