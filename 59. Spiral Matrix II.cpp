//这个题的思路和上一题不同
//方法是每一次剥开一层，起点往右下方走一次。
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int numn = n - 1;
        int x = 0;
        int y = 0;
        int k = 1;
        while(numn > 0) {
            for(int i = 0; i < numn; i++, y++)
                ret[x][y] = k++;
            for(int i = 0; i < numn; i++, x++)
                ret[x][y] = k++;
            for(int i = 0; i < numn; i++, y--)
                ret[x][y] = k++;
            for(int i = 0; i < numn; i++, x--)
                ret[x][y] = k++;
            x++;
            y++;
            numn -= 2;
        }
        if(n % 2 == 1)
            ret[x][y] = k;
        return ret;
    }
};