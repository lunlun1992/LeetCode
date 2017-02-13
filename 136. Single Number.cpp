class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int num = 0;
        for(int i = 0; i < len; i++)
        {
            num ^= nums[i];
        }
        return num;
    }
};