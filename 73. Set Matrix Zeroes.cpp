//以第一行和第一列作为flag
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(!row)
            return;
        int col = matrix[0].size();
        
        bool firstcolzero = false;
        bool firstrowzero = false;
        
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0)
                firstcolzero = true
        for(int j = 0; j < col; j++)
            if(matrix[0][j] == 0)
                firstrowzero = true;
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < row; i++)
            if(matrix[i][0] == 0)
                for(int j = 1; j < col; j++)
                    matrix[i][j] = 0;
        for(int j = 1; j < col; j++)
            if(matrix[0][j] == 0)
                for(int i = 1; i < row; i++)
                    matrix[i][j] = 0;
        
        if(firstcolzero)
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
        if(firstrowzero)
            for(int j = 0; j < col; j++)
                matrix[0][j] = 0;
    }
};