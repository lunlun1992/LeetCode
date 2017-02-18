//环形检测算法，一个快一个慢，很快就能够检测到了
class Solution {
public:
    int digitSquareSum(int n) 
    {
        int sum = 0, tmp;
        while (n) 
        {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        int slow, fast;
        slow = fast = n;
        do 
        {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};