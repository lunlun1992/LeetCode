class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int len = nums.size();
        if(!len)
            return 0;
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(), INT_MIN);
        int b = 1;
        int e = len;
        while(b < e) {
            int m = b + ((e - b) >> 1);
            if(nums[m] >= nums[m - 1] && nums[m] >= nums[m + 1])
                return m - 1;
            else if(nums[m] >= nums[m - 1] && nums[m] < nums[m + 1])
                b = m + 1;
            else
                e = m;
        }
        return b - 1;
    }
};