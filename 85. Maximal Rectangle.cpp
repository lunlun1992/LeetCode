//将问题转化为确定正上方的1高度，然后找到左右边界的问题，和上一次做的最大矩形差不多。
//具体方法是：确定高度，很简单，每一行维护一个height数组就行了。
//确定左右边界时，就跟上一行和本行有关。上一行累计的左边界和本行的左边界之中的较小者，就是本行的实际左边界。
//然后用height * (right-left)即可。
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
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            
            int curleft = 0;
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '0')
                {
                    curleft = j + 1;
                    left[j] = 0;
                }
                else
                {
                    left[j] = max(curleft, left[j]);
                }
            }
            
            int curright = col - 1;
            for(int j = col - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '0')
                {
                    curright = j - 1;
                    right[j] = col - 1;
                }
                else
                {
                    right[j] = min(curright, right[j]);
                }
            }
            
            for(int j = 0; j < col; j++)
                ret = max(ret, height[j] * (right[j] - left[j] + 1));
        }
        return ret;
    }
};