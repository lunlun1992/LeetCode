class Solution {
public:
    int help(vector<int> &v) {
        int len = v.size();
        sort(v.begin(), v.end());
        int i = 0;
        int j = len - 1;
        int ret = 0;
        while(i < j)
            ret += (v[j--] - v[i++]);
        return ret;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();
        if (!col)
            return 0;
        vector<int> cols;
        vector<int> rows;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j]) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return help(cols) + help(rows);
    }
};