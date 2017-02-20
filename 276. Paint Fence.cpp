//大致意思是，不能三连一样颜色
//所以0，1不一样颜色有k(k-1)种，一样有k种
//1，2不一样颜色有k * k * (k - 1)种, 一样颜色有k(k - 1)种
public class Solution {
    public int numWays(int n, int k)
    {
        if(n == 0) 
            return 0;
        else if(n == 1) 
            return k;
        int diffColorCounts = k * (k - 1);
        int sameColorCounts = k;
        for(int i = 2; i < n; i++) 
        {
            int temp = diffColorCounts;
            diffColorCounts = (diffColorCounts + sameColorCounts) * (k - 1);
            sameColorCounts = temp;
        }
        return diffColorCounts + sameColorCounts;    
    }
}