class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ma = nums[0];
        int count = 0;
        for (auto n : nums) {
            if (n == ma) {
                count++;
            } else if (count == 0) {
                ma = n;
                count = 1;
            } else {
                count--;
            }
        }
        return ma;
    }
};