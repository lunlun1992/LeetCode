//注意一些细节
//首先是n=0或者x=1，x=0时直接算出来
//然后是n<0时变成正数来算，最后再加回去。
class Solution {
public:
    double myPow(double x, int n) 
    {
        int64_t nn = (int64_t)n;
        bool nega = false;
        if(n == 0 || x == 1)
            return 1;
        else if(x == 0)
            return 0;
        else if(n < 0)
        {
            nega = true;
            nn = -nn;
        }
        
        //n > 0, x != 0
        double mul = x;
        double ret = 1;
        while(nn)
        {
            if(nn & 1)
                ret *= mul;
            nn >>= 1;
            mul *= mul;
        }
        return nega ? 1 / ret : ret;
    }
};