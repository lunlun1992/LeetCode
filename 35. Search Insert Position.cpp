//二分法的应用
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if(nums.empty())
            return 0;
        int len = nums.size();
        int b = 0;
        int e = len;
        
        while(b < e)
        {
            int m = b + ((e - b) >> 1);
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                b = m + 1;
            else
                e = m;
        }
        
        return e;
        
    }
};