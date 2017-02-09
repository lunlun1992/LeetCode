//模拟题，需要记录行的左右终点和列的左右终点。
//然后进行旋转即可，注意有些时候需要判定下标的合法性。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if(!m)
            return {};
        int n = matrix[0].size();
        vector<int> ret;
        
        int rb = 0;
        int re = m - 1;
        int cb = 0;
        int ce = n - 1;
        
        while(rb <= re && cb <= ce)
        {
            for(int y = cb; y <= ce; y++)
                ret.push_back(matrix[rb][y]);
            rb++;
            
            for(int x = rb; x <= re; x++)
                ret.push_back(matrix[x][ce]);
            ce--;
            
            if(rb > re)//下面这个循环需要这个合法性，否则跳出
                break;
            for(int y = ce; y >= cb; y--)
                ret.push_back(matrix[re][y]);
            re--;
            
            if(cb > ce)//下面这个循环需要这个合法性，否则跳出
                break;
            
            for(int x = re; x >= rb; x--)
                ret.push_back(matrix[x][cb]);
            cb++;
        }
        return ret;
    }
};