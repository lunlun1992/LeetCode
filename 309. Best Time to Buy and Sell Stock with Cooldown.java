//双数组的dp，sell以及buy代表在第i天买或者在第i天卖。
//递推关系是：在第i天买等价于在第i-2天卖或者在i-1天持有（不买）。
public int maxProfit(int[] prices)
    {
        int len = prices.length; 
        if(len == 0 || len == 1)
            return 0;
        int[] sells = new int[len];
        int[] buys = new int[len];
        sells[0] = 0;
        buys[0] = -prices[0];
        for(int i = 1; i < len; i++)
        {
            sells[i] = Math.max(sells[i - 1] - prices[i - 1] + prices[i], buys[i - 1] + prices[i]);
            if(i >= 2)
            {
                buys[i] = Math.max(sells[i - 2] - prices[i], buys[i - 1] - prices[i] + prices[i - 1]);
            }
            else
            {
                buys[i] = buys[i - 1] - prices[i] + prices[i - 1];
            }
        }
        int max = 0;
        for(int i = 0; i < len; i++)
        {
            max = max > sells[i] ? max : sells[i];
        }
        return max;
    }