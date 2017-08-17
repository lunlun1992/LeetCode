class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = 1;
        while (m != n) {
            m &= ~bit;
            n &= ~bit;
            bit <<= 1;    
        }
        return m;
    }
};