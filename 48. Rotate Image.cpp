//先对折，再调换
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        //1. fold
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - 1 - i; j++)
            {
                int nexti = n - 1 - j;
                int nextj = n - 1 - i;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[nexti][nextj];
                matrix[nexti][nextj] = temp;
            }
        }
        
        //2. switch
        int s = 0;
        int e = n - 1;
        while(s < e)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = matrix[s][j];
                matrix[s][j] = matrix[e][j];
                matrix[e][j] = temp;
            }
            s++;
            e--;
        }
        
    }
};