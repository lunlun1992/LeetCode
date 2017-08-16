class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> sum(len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                sum[i] = sum[i - 1] + 1;
            }
        }
        
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                sum[i] = max(sum[i], sum[i + 1] + 1);
            }
        }
        
        int ret = 0;
        for (auto n : sum) {
            ret += n;
        }
        return ret;
    }
};