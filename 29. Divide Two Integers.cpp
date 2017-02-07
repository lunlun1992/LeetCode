//方法是先确定符号，然后每次减去最大的除数的倍数。
//尽可能减少减法的次数，用移位的次数补偿。
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        int64_t big = labs(dividend);
        int64_t small = labs(divisor);
        
        int ans = 0;
        while(big >= small)
        {
            int64_t multi = 1;
            int64_t temp = small;
            while(big > (temp << 1))
            {
                temp <<= 1;
                multi <<= 1;
            }
            ans += multi;
            big -= temp;
        }
        return sign * ans;
    }
};