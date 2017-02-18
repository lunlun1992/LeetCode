//和super ugly number一样的算法，就是要遍历所有质数的乘积。
//方法是记录每一个质数使用过的次数，然后从小到大排列。
//排列方法是每次取最小的那一个。
class Solution {
public:
#define MIN(a,b) ((a) < (b) ? (a) : (b))
    int nthUglyNumber(int n)
    {
        int index[3] = {0, 0, 0};
        int factors[3] = {2, 3, 5};
        vector<int> res(n);
        res[0] = 1;
        for(int i = 1; i < n; i++)
        {
            int min = 0x7fffffff;
            for(int j = 0; j < 3; j++)
            {
                min = MIN(min, factors[j] * res[index[j]]);
            }
            res[i] = min;
            for(int j = 0; j < 3; j++)
                if(min % factors[j] == 0)
                    index[j]++;
        }
        return res[n - 1];
    }
};