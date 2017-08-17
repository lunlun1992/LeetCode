class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int div = 5;
        while (n) {
            count += n / div;
            n /= div;
        }
        return count;
    }
};