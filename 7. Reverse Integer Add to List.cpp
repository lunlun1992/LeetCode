//都是陷阱
//首先确保都是正的，然后64位，这样不会溢出
class Solution {
public:
    int reverse(int x) 
    {
        bool isnaga = x < 0 ? true : false;
        int64_t xx = (int64_t)x;
        xx = xx < 0 ? -xx : xx;
        int64_t ret = 0;
        while(xx)
        {
            ret *= 10;
            ret += xx % 10;
            xx /= 10;
        }
        if(ret > 0x7fffffff)
            return 0;
        else
            return isnaga ? -ret : ret;
    }
};