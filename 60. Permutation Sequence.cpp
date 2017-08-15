//计算每一次循环代表的周期次数
class Solution {
public:

    string getPermutation(int n, int k) {
        string ret;
        vector<int> factors(n + 1);
        vector<int> v(n + 1);
        for(int i = 0; i < n; i++)
            v[i] = i + 1;
        factors[1] = factors[0] = 1;
        for(int i = 2; i <= n; i++)
            factors[i] = i * factors[i - 1];
        for(int i = n - 1; i >= 0; i--) {
            int idx = (k - 1) / factors[i];			//acquire the idx of the last round
            ret.push_back(v[idx] + '0');
            k -= idx * factors[i];					//eliminate the rounds
            for (int j = idx; j < v.size(); j++)	//move the array
                v[j] = v[j + 1];
            v.pop_back();
        }
        return ret;
    }
};
