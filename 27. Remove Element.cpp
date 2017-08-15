//还是一样维护两个指针
//0-i是没有val的那部分
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = -1;
        for (int i = 0; i < nums.size(); i++)
            if(nums[i] != val)
                nums[++k] = nums[i];
        return k + 1;
    }
};