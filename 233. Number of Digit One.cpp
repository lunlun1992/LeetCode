//每次考虑一个数位上面的1的个数。
//(n / m + 8) / 10 * m代表的是当前数位上的整周期1的个数，每一个周期m个1，周期数用n/m/10 + 1来算，这一位是0或者1的时候不能加1，所以用一个trick+8来解决。
//如果是0就算了，如果是1，那就要计算出现了多少次，一共n%m + 1次。
class Solution {
public:
    int countDigitOne(int n)
    {
        int ones = 0;
        for (int64_t m = 1; m <= n; m *= 10)
            ones += (n / m + 8) / 10 * m + ((n / m) % 10 == 1) * (n % m + 1);
        return ones;
    }
};