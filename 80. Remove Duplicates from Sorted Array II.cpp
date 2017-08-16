//重复利用之前的空间
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < 2 || nums[j - 2] != nums[i]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};