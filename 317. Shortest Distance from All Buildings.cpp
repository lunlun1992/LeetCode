//这是没有2的时候的最好方案
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int ret = INT_MAX;
        vector<int> ansrow(r, 0);
        vector<int> anscol(c, 0);
        vector<int> rowsum(r, 0);
        vector<int> colsum(c, 0);
        vector<int> prevrowsum(r, 0);
        vector<int> prevcolsum(c, 0);
        vector<int> prevrowdist(r, 0);
        vector<int> prevcoldist(c, 0);
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(grid[i][j] == 1)
                {
                    rowsum[i]++;
                    colsum[j]++;
                }
        
        //row
        prevrowsum[0] = rowsum[0];
        for(int i = 1; i < r; i++)
            prevrowsum[i] = prevrowsum[i - 1] + rowsum[i];
        prevrowdist[0] = 0;
        for(int i = 1; i < r; i++)
        {
            prevrowdist[i] = prevrowdist[i - 1] + prevrowsum[i - 1];
            ansrow[i] = prevrowdist[i];
        }
        
        prevrowsum[r - 1] = rowsum[r - 1];
        for(int i = r - 2; i >= 0; i--)
            prevrowsum[i] = prevrowsum[i + 1] + rowsum[i];
        prevrowdist[r - 1] = 0;
        for(int i = r - 2; i >= 0; i--)
        {
            prevrowdist[i] = prevrowdist[i + 1] + prevrowsum[i + 1];
            ansrow[i] += prevrowdist[i];
        }
        
        //col
        prevcolsum[0] = colsum[0];
        for(int j = 1; j < c; j++)
            prevcolsum[j] = prevcolsum[j - 1] + colsum[j];
        prevcoldist[0] = 0;
        for(int j = 1; j < c; j++)
        {
            prevcoldist[j] = prevcoldist[j - 1] + prevcolsum[j - 1];
            anscol[j] = prevcoldist[j];
        }
        
        prevcolsum[c - 1] = colsum[c - 1];
        for(int j = c - 2; j >= 0; j--)
            prevcolsum[j] = prevcolsum[j + 1] + colsum[j];
        prevcoldist[c - 1] = 0;
        for(int j = c - 2; j >= 0; j--)
        {
            prevcoldist[j] = prevcoldist[j + 1] + prevcolsum[j + 1];
            anscol[j] += prevcoldist[j];
        }
            
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(grid[i][j] == 0)
                    ret = min(ret, anscol[j] + ansrow[i]);
        return ret;
    }
};


//BFS的方法，非常优化了
class Solution {
public:
    int shortestDistance(vector<vector<int>> grid)
    {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 1) 
                {
                    mindist = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (q.size()) 
                    {
                        auto ij = q.front();
                        q.pop();
                        for(int d = 0; d < 4; ++d) 
                        {
                            int i = ij.first + delta[d];
                            int j = ij.second + delta[d + 1];
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk)
                            {
                                grid[i][j]--;
                                dist[i][j] = dist[ij.first][ij.second] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.emplace(i, j);
                                if (mindist < 0 || mindist > total[i][j])
                                    mindist = total[i][j];
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return mindist;
    }
};