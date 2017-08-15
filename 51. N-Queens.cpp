/**    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  */
//重要的是那个flag数组。
//我采用的方式是一共有三个不同的方向类型，每放一颗棋子，就会disable某一方向上的某一行
//这样可以不用维护一个特殊的map，flag的维护负担比较小。
//而且这还是一个先递归，所以叶节点在开头比较难找，和之前的DFS不同。
class Solution {
public:
    void dfs(int row, int col, int n, vector<bool> &flag_col, vector<bool> &flag_45, vector<bool> &flag_135) {
        int nextrow = row + 1;
        if(nextrow == n) {
            ret.push_back(now);
            return;
        }
        for(int j = 0; j < n; j++) {
            if(flag_col[j] && flag_45[nextrow + j] && flag_135[n - 1 + j - nextrow]) {
                flag_col[j] = false;
                flag_45[nextrow + j] = false;
                flag_135[n - 1 + j - nextrow] = false;
                now[nextrow][j] = 'Q';
                
                dfs(nextrow, j, n, flag_col, flag_45, flag_135);
            
                flag_col[j] = true;
                flag_45[nextrow + j] = true;
                flag_135[n - 1 + j - nextrow] = true;
                now[nextrow][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        string str(n, '.');
        for(int i = 0; i < n; i++)
            now.push_back(str);
        vector<bool> flag_col(n, true);
        vector<bool> flag_45(2 * n - 1, true);
        vector<bool> flag_135(2 * n - 1, true);
        for(int j = 0; j < n; j++) {
            flag_col[j] = false;
            flag_45[0 + j] = false;
            flag_135[n - 1 + j - 0] = false;
            now[0][j] = 'Q';
            
            dfs(0, j, n, flag_col, flag_45, flag_135);
            
            flag_col[j] = true;
            flag_45[0 + j] = true;
            flag_135[n - 1 + j - 0] = true;
            now[0][j] = '.';
        }
        return ret;
    }
private:
    vector<vector<string>> ret;
    vector<string> now;
};