//凡是有重复，就当前后指针相等的时候向前走
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int len = nums.size();
        if(len <= 0)
            return 0;
        int l = 0;
        int r = len - 1;
        while(l != r && nums[l] == nums[r])
            l++;
        while(nums[l] > nums[r])
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid;
            while(l != r && nums[l] == nums[r])
                l++;
        }
        return nums[l];
    }
};