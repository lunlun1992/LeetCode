class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ret = 0;
        for(int i = 0; i < len - 1; i++) {
            int diff = prices[i + 1] - prices[i];
            if(diff > 0)
                ret += diff;
        }
        return ret;
    }
};