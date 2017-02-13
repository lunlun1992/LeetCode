//找到之前的最小值，只交易一次的话可以这样做
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if(!len)
            return 0;
        int mini = prices[0];
        int ret = 0;
        for(int i = 1; i < len; i++)
        {
            if(prices[i] > mini)
                ret = max(ret, prices[i] - mini);
            else
                mini = min(mini, prices[i]);
        }
        
        return ret;
    }
};