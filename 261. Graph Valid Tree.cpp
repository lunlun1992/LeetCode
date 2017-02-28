class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
        vector<int> root;
        for(int i = 0; i < n; i++)
            root.push_back(i);
        int len = edges.size();
        if(len != n - 1)//无环时应该有n-1条边
            return false;
        for(int i = 0; i < len; i++)//确定无环的算法
        {
            int f = edges[i].first;
            int s = edges[i].second;
            while(root[f] != f)
                f = root[f];
            while(root[s] != s)
                s = root[s];
            if(s == f)
                return false;
            root[s] = f;
        }
        return true;
    }
};