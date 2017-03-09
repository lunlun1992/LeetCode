//BFS标准体
class Solution {
public:

    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        int r = rooms.size();
        if(!r)
            return;
        int c = rooms[0].size();
        if(!c)
            return;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(!rooms[i][j])
                {
                    que.push(P(i, j));
                    rooms[i][j] = INT_MAX;
                }
        int depth = 0;
        while(!que.empty())
        {
            int len = que.size();
            for(int i = 0; i < len; i++)
            {
                P p = que.front();
                que.pop();
                if(p.first < 0 || p.first >= r || p.second < 0 || p.second >= c || rooms[p.first][p.second] != INT_MAX)
                    continue;
                que.push(P(p.first + 1, p.second));
                que.push(P(p.first - 1, p.second));
                que.push(P(p.first, p.second + 1));
                que.push(P(p.first, p.second - 1));
                rooms[p.first][p.second] = depth;
                
            }
            depth++;
        }
    }
private:
    typedef pair<int, int> P;
    queue<P> que;
};