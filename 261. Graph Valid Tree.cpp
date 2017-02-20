class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
        vector<int> nodes(n,0);
        for(int i = 0; i < n; i++) 
            nodes[i] = i;
        for(int i = 0; i < edges.size(); i++)//证明没有环
        {
            int f = edges[i].first;
            int s = edges[i].second;
            while(nodes[f] != f) 
                f = nodes[f];
            while(nodes[s] != s)//只有根节点的idx和node[idx]相等 
                s = nodes[s];
            if(nodes[f] == nodes[s])
                return false;
            nodes[s] = f;
        }
        return edges.size() == n - 1;//没有环时，证明全连接
    }
};