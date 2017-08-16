class Solution {
public:
    typedef pair<int, int> P;
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int ret = 0;
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            
            int curleft = 0;                            //本列左边连续的最后一个1的index
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    left[j] = 0;
                    curleft = j + 1;
                } else {
                    left[j] = max(curleft, left[j]);    //确定本高度下，其左边的边界在哪里
                }
            }
            
            int curright = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    right[j] = col - 1;
                    curright = j - 1;
                } else {
                    right[j] = min(right[j], curright);
                }
            }
            
            for (int j = 0; j < col; j++) {
                ret = max(ret, (right[j] - left[j] + 1) * height[j]);
            }
        }
        return ret;
    }
};