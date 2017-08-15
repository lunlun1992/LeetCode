//0~i是不重复的部分
//i+1~j-1是完全重复的部分
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 1;
        for(int j = 1; j < nums.size(); j++)
            if(nums[j] != nums[j - 1])
                nums[i++] = nums[j];
        return i;
    }
};