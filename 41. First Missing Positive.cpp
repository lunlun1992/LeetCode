//把正数交换到对应位置上，然后再扫描一遍，找到第一个不正确的数字
//有两种情况不进行交换
//1. 本位置上的数字不在合理范围内
//2. 要交换的两个数字相等
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if(nums.empty())
            return 1;
        int len = nums.size();
        int idx = 0;
        while(idx < len)
        {
            if(idx + 1 != nums[idx])
            {
                if(nums[idx] > len || nums[idx] < 1 || nums[idx] == nums[nums[idx] - 1])
                    idx++;
                else
                {
                    int temp = nums[idx];
                    nums[idx] = nums[nums[idx] - 1];
                    nums[temp - 1] = temp;
                }
            }
            else
                idx++;
        }
        
        for(int i = 0; i < len; i++)
            if(i + 1 != nums[i])
                return i + 1;
        return len + 1;
    }
};