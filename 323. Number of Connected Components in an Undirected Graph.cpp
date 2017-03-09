class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) 
    {
        if(!n)
            return 0;
        vector<int> G[n];
        vector<bool> used(n, false);
        for(auto p : edges)
        {
            G[p.first].push_back(p.second);
            G[p.second].push_back(p.first);
        }
        int ret = 0;
        for(int i = 0; i < n; i++)
        {
            if(used[i])
                continue;
            dfs(G, used, i);
            ret++;
        }
        return ret;
    }
private:
    void dfs(const vector<int> *G, vector<bool> &used, int idx)
    {
        used[idx] = true;
        int len = G[idx].size();
        for(int i = 0; i < len; i++)
            if(!used[G[idx][i]])
                dfs(G, used, G[idx][i]);
    }
};