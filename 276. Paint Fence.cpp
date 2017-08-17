class Solution {
public:
    int numWays(int n, int k) 
    {
        if(n == 0)
            return 0;
        else if(n == 1)
            return k;
        int diff = (k - 1) * k; //n = 2
        int same = k;
        
        for (int i = 3; i <= n; i++) {
            int lastsame = same;
            same = diff;
            diff = (k - 1) * (lastsame + diff);
        }
        return same + diff;
    }
};