//双数组的dp，sell以及buy代表在第i天买或者在第i天卖。
//递推关系是：在第i天买等价于在第i-2天卖或者在i-1天持有（不买）。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<int> sells(len, 0);
        vector<int> buys(len, 0);
        buys[0] = -prices[0];

        for (int i = 1; i < len; i++) {
            sells[i] = max(sells[i - 1] - prices[i - 1] + prices[i], buys[i - 1] + prices[i]);
            if (i >= 2) {
                buys[i] = max(sells[i - 2] - prices[i], buys[i - 1] - prices[i] + prices[i - 1]);
            } else {
                buys[i] = buys[i - 1] - prices[i] + prices[i - 1];
            }
        }
        int maxi = 0;
        for (int i = 0; i < len; i++) {
            maxi = maxi > sells[i] ? maxi : sells[i];
        }
        return maxi;
    }
};