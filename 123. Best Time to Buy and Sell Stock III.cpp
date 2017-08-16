//以某一天作为分界点，在此天之前做过一次交易，在此天之后做过另外一次交易
//只需要做两次动态规划即可，得到此天前的最大收益以及此天后的最大收益，找到相加最大值即可。
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size();
        if(len < 2)
            return 0;
        vector<int> preprofit(len, 0);
        vector<int> postprofit(len, 0);
        int ret = INT_MIN;
        
        int mini = INT_MAX;
        for (int i = 1; i < len; i++) {
            mini = min(mini, prices[i - 1]);
            preprofit[i] = max(preprofit[i - 1], prices[i] - mini);
        }
        
        int maxi = INT_MIN;
        for (int i = len - 1; i > 0; i--) {
            maxi = max(maxi, prices[i]);
            postprofit[i - 1] = max(postprofit[i], maxi - prices[i - 1]);
        }
        
        for (int i = 0; i < len; i++) {
            ret = max(ret, preprofit[i] + postprofit[i]);
        }
        
        return ret;
    }
};