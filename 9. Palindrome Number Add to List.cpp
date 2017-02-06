//1.负数都不是
//2.把数倒过来，看是否相等即可。
class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        int y = 0;
        int newx = x;
        while(newx)
        {
            y *= 10;
            y += newx % 10;
            newx /= 10;
        }
        return x == y;
    }
};