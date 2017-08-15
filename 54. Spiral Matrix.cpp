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
        while(rb <= re && cb <= ce) {
            for (int j = cb; j <= ce; j++) {
                ret.push_back(matrix[rb][j]);
            }
            rb++;
            if (rb > re)
                break;
            
            for (int i = rb; i <= re; i++) {
                ret.push_back(matrix[i][ce]);
            }
            ce--;
            if (cb > ce)
                break;
            
            for (int j = ce; j >= cb; j--) {
                ret.push_back(matrix[re][j]);
            }
            re--;
            if (rb > re)
                break;
            
            for (int i = re; i >= rb; i--) {
                ret.push_back(matrix[i][cb]);
            }
            cb++;
        }
        return ret;
    }
};