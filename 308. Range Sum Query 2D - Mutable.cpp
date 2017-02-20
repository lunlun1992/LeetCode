//BIT很合理
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) 
    {
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();
        if(!n)
            return;
        ma.assign(m, vector<int>(n, 0));
        tree.assign(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                update(i, j, matrix[i][j]);
        
    }
    
    void update(int row, int col, int val)
    {
        //cout << m << " " << n << endl;
        if(m == 0 || n == 0)
            return;
        int diff = val - ma[row][col];
        ma[row][col] = val;
        for(int i = row + 1; i <= m; i += i & (-i))
            for(int j = col + 1; j <= n; j += j & (-j))
                tree[i][j] += diff;
                
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(m == 0 || n == 0)
            return 0;
        return sum(row2, col2) + sum(row1 - 1, col1 - 1) - sum(row1 - 1, col2) - sum(row2, col1 - 1);
    }
    
private:
    vector<vector<int>> tree;
    vector<vector<int>> ma;
    int m;
    int n;
    int sum(int r, int c)
    {
        int ret = 0;
        for(int i = r + 1; i > 0; i -= i & (-i))
            for(int j = c + 1; j > 0; j -= j & (-j))
                ret += tree[i][j];
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */