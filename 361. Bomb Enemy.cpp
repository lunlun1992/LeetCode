//设置一个本行和本列可以炸到的敌人个数，然后用这种方法计算
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        if(!m)
            return 0;
        int n = grid[0].size();
        int ret = 0;
        int rowhits = 0;
        vector<int> colhits(n, 0);
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (!j || grid[i][j - 1] == 'W') 
                {
                    rowhits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        rowhits += (grid[i][k] == 'E');
                }
                if (!i || grid[i - 1][j] == 'W') 
                {
                    colhits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        colhits[j] += (grid[k][j] == 'E');
                }
                if (grid[i][j] == '0')
                    ret = max(ret, rowhits + colhits[j]);
            }
        }
        return ret;
    }
};