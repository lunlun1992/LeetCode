class Solution {
public:
    void dfs(int n)
    {
        if(n == 1)
        {
            ret.push_back(now);
            return;
        }
        int i = now.empty() ? 2 : now.back();
        for(; i <= n; i++)
        {
            if(n % i == 0)
            {
                now.push_back(i);
                dfs(n / i);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) 
    {
        dfs(n);
        ret.pop_back();//remove n itself
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};