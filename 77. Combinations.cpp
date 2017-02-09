//DFS，由于是组合所以肯定不会复用
class Solution {
public:
    void dfs(int idx, int k, int n)
    {
        if(k == 0)
        {
            ret.push_back(now);
            return;
        }
        else if(idx > n)
            return;
        
        for(int i = idx; i <= n; i++)
        {
            now.push_back(i);
            dfs(i + 1, k - 1, n);
            now.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        if(k > n)
            return ret;
        dfs(1, k, n);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};