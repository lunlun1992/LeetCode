//和super ugly number一样的算法，就是要遍历所有质数的乘积。
//方法是记录每一个质数使用过的次数，然后从小到大排列。
//排列方法是每次取最小的那一个。
class Solution {
public:
    int nthUglyNumber(int n) {
        int index[3] = {0, 0, 0};
        int factors[3] = {2, 3, 5};
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < 3; j++) {
                mini = min(mini, factors[j] * res[index[j]]);
            }
            res[i] = mini;
            for(int j = 0; j < 3; j++)
                if(mini % factors[j] == 0)
                    index[j]++;
        }
        return res[n - 1];
    }
};