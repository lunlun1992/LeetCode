//组合数的递推
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<int> ret;
        int num = 1;      
        for(int i = 0; i < rowIndex + 1; i++) {
            ret.push_back(num);
            num = ((int64_t)num) * (rowIndex - i) / (i + 1);
        }
        return ret;
    }
};