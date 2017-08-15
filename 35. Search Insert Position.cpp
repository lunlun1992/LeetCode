//lower_bound，以后都这么写。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int m = s + ((e - s) >> 1);
            if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
};