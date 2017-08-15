//把整数倒过来即可
class Solution {
public:
    int reverse(int x) 
    {
        int64_t absx = abs((int64_t)x);
        int64_t ret = 0;
        while(absx) {
            ret *= 10;
            ret += (absx % 10);
            absx /= 10;
        }
        return x < 0 ? (-ret < INT_MIN ? 0 : -ret) : (ret > INT_MAX ? 0 : ret);
    }
};