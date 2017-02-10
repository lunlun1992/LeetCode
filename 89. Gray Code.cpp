//
class Solution {
public:
    vector<int> grayCode(int n) 
    {
        int len = 1 << n;
        vector<int> ret(len, 0);
        bool even = true;
        int num = 0;
        for(int i = 1; i < len; i++)
        {
            if(even)
                num ^= 1;//第偶数个数，最后一位取反
            else
                num ^= (num - (num & (num - 1))) << 1;//第奇数个数，将最右边的1的左边紧邻的bit取反
            even = !even;
            ret[i] = num;
        }
        return ret;
    }
};