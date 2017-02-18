class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int len = nums.size();
        int b = 0;
        int e = len - 1;
        while(nums[b] > nums[e])
        {
            int m = b + ((e - b) >> 1);
            if(nums[b] <= nums[m])
                b = m + 1;
            else
                e = m;
        }
        return nums[b];
    }
};