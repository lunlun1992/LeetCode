//0~i是不重复的部分
//i+1~j-1是完全重复的部分
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        int i = 0;
        int j = 1;
        int len = nums.size();
        while(j < len)
        {
            if(nums[j] == nums[j - 1])
                j++;
            else
                nums[++i] = nums[j++];
        }
        return i + 1;
        
    }
};