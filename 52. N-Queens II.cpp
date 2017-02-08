//和上一题一样的思路，不赘述
class Solution {
public:
    void dfs(int row, int col, int n, vector<bool> &flag_col, vector<bool> &flag_45, vector<bool> &flag_135)
    {
        int nextrow = row + 1;
        if(nextrow == n)
        {
            ret++;
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(flag_col[j] && flag_45[nextrow + j] && flag_135[n - 1 + j - nextrow])
            {
                flag_col[j] = false;
                flag_45[nextrow + j] = false;
                flag_135[n - 1 + j - nextrow] = false;
                
                dfs(nextrow, j, n, flag_col, flag_45, flag_135);
            
                flag_col[j] = true;
                flag_45[nextrow + j] = true;
                flag_135[n - 1 + j - nextrow] = true;
            }
        }
    }

    int totalNQueens(int n) 
    {
        vector<bool> flag_col(n, true);
        vector<bool> flag_45(2 * n - 1, true);
        vector<bool> flag_135(2 * n - 1, true);
        for(int j = 0; j < n; j++)
        {
            flag_col[j] = false;
            flag_45[0 + j] = false;
            flag_135[n - 1 + j - 0] = false;
            
            dfs(0, j, n, flag_col, flag_45, flag_135);
            
            flag_col[j] = true;
            flag_45[0 + j] = true;
            flag_135[n - 1 + j - 0] = true;
        }
        return ret;
    }
private:
    int ret;
};