//注意一些细节
//首先是n=0或者x=1，x=0时直接算出来
//然后是n<0时变成正数来算，最后再加回去。
class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        double multi = x;
        bool isnega = n < 0;
        int64_t nn = n;
        nn = abs(nn);
        while (nn) {
            int bit = nn & 1;
            ret *= bit ? multi : 1;
            multi *= multi;
            nn >>= 1;
        }
        return isnega ? 1 / ret : ret;
    }
};