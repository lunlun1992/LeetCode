//在结果数组上面标记好开始和结束区域
//然后用accu作为本位置上应该加的值，赋值好即可
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
    {
        vector<int> ret(length, 0);
        for(auto it : updates)
        {
            ret[it[0]] += it[2];
            if(it[1] < length - 1)
                ret[it[1] + 1] -= it[2];
        }
        
        int accu = 0;
        for(int i = 0; i < length; i++)
        {
            accu += ret[i];
            ret[i] = accu;
        }
        return ret;
    }
};