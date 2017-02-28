class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int len = nums.size();
        int miss = len;
        for(int i = 0; i < len; i++)
        {
            while(nums[i] != i)
            {
                if(nums[i] == len)
                {
                    miss = i;
                    break;
                }
                swap(nums[nums[i]], nums[i]);
            }
        }
        return miss;
    }
};