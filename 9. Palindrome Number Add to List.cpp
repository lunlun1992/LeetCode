//1.负数都不是
//2.把数倒过来，看是否相等即可。
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int64_t y = 0;
        int64_t tmp = x;
        while(tmp) {
            y *= 10;
            y += (tmp % 10);
            tmp /= 10;
        }
        return y == x;
    }
};