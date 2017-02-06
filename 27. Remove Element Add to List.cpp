//还是一样维护两个指针
//0-i是没有val的那部分
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = -1;
        int j = 0;
        int len = nums.size();
        while(j < len)
        {
            if(nums[j] == val)
                j++;
            else
                nums[++i] = nums[j++];
        }
        return i + 1;
    }
};