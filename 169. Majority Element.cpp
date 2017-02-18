class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ma = nums[0];
        int count = 1;
        int len = nums.size();
        for(int i = 1; i < len; i++)
        {
            if(count == 0)
            {
                count++;
                ma = nums[i];
            }
            else if(ma == nums[i])
                count++;
            else
                count--;
        }
        return ma;
    }
};