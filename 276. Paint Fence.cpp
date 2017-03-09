class Solution {
public:
    int numWays(int n, int k) 
    {
        if(n == 0)
            return 0;
        else if(n == 1)
            return k;
        int diff = k * (k - 1);//0 and 1 have different colors
        int same = k;          //0 and 1 have same colors
        for(int i = 2; i < n; i++)
        {
            int lastdiff = diff;
            diff = same * (k - 1) + diff * (k - 1);//i - 1 and i have different colors
            same = lastdiff;                       //i - 1 and i have same colors
        }
        return same + diff;
    }
};