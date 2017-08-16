class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (auto n : nums) {
                if ((1 << i) & n) {
                    ++count;
                }
            }
            if (count % 3)
                ret |= (1 << i);
        }
        return ret;
    }
};