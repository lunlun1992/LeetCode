//还是在右上角搜索，若大则不在这一行，若小则不在这一列。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        if(!row)
            return false;
        int col = matrix[0].size();
        
        int i = 0;
        int j = col - 1;
        while(i < row && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};