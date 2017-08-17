class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int b = 0;
        int e = 0;
        int ret = INT_MAX;
        while (e < len) {
            while (e < len && sum < s) {
                sum += nums[e++];
            }
            if (sum < s)
                break;
            while (b < e && sum >= s) {
                sum -= nums[b++];
            }
            ret = min(ret, e - b + 1);
        }
        return ret == INT_MAX ? 0 : ret;
    }
};