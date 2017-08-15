//把正数交换到对应位置上，然后再扫描一遍，找到第一个不正确的数字
//有两种情况不进行交换
//1. 本位置上的数字不在合理范围内
//2. 要交换的两个数字相等
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for(int i = 0; i < len; i++)
            if(nums[i] != i + 1)
                return i + 1;
        return len + 1;
    }
};