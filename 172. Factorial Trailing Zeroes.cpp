//看有多少个5作为因子即可
class Solution {
public:
    int trailingZeroes(int n)
    {
        int64_t five = 5;
        int64_t ret = 0;
        while(n >= five)
        {
            ret += n / five;
            five *= 5;
        }
        return (int)ret;
    }
};