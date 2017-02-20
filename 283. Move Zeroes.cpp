class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int b = -1;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            if(nums[i] != 0)
                nums[++b] = nums[i];
        while(b < len - 1)
            nums[++b] = 0;
    }
};