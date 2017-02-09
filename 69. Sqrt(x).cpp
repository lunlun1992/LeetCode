//牛顿法，注意细节。
class Solution {
public:
    int mySqrt(int x) 
    {
        int a = x;
        int b = 1;
        while(abs(a - b) > 1)
        {
            b = min(a, b) + abs(b - a) / 2;
            a = x / b;
        }
        return min(a, b);
    }
};