//题意：找到[2, 3, 5...]质数的所有乘积，然后取出其第n个。
//肯定是乘啦，怎么乘？全部乘在一起有可能漏。
//所以引入index[j]数组：第j个质数使用过的次数。每次取出相乘最小的值，然后判断这个最小值中的质因数有没有primes数组中的数，如果有，则对应index+1。这样primes数组中乘以res中对应位置的数是当前最小的。
//看做一个用许多质数凑乘积的过程。
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> ret(n, 0);
        ret[0] = 1;
        for (int i = 1; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                mini = min(mini, primes[j] * ret[idx[j]]);
            }
            ret[i] = mini;
            for (int j = 0; j < primes.size(); j++) {
                if (mini % primes[j] == 0) {
                    idx[j]++;
                }
            }
        }
        return ret[n - 1];
    }
};