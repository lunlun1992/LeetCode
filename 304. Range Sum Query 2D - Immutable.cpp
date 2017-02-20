//采用构造累加数组的方法，每次query的时候只需要简单的几步操作就能完成任务。
class NumMatrix {
private:
    vector<vector<int>> accumulate_matrix;
    int rows;
    int cols;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        rows = matrix.size();
        if(rows == 0)
            return;
        cols = matrix[0].size();
        if(cols == 0)
            return;
        for(int i = 0; i < rows; i++)
        {
            vector<int> temp(cols, 0);
            accumulate_matrix.push_back(temp);
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                accumulate_matrix[i][j] = matrix[i][j];
                if(i >= 1)
                    accumulate_matrix[i][j] += accumulate_matrix[i - 1][j];
                if(j >= 1)
                    accumulate_matrix[i][j] += accumulate_matrix[i][j - 1];
                if(i >= 1 && j >= 1)
                    accumulate_matrix[i][j] -= accumulate_matrix[i - 1][j - 1];
            }
        }   
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ret = accumulate_matrix[row2][col2];
        if(row1 >= 1)
            ret -= accumulate_matrix[row1 - 1][col2];
        if(col1 >= 1)
            ret -= accumulate_matrix[row2][col1 - 1];
        if(row1 >= 1 && col1 >= 1)
            ret += accumulate_matrix[row1 - 1][col1 - 1];
        return ret;   
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);