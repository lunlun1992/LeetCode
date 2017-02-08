//两次二分法即可。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty())
            return {-1, -1};
        int len = nums.size();
        int s = 0;
        int e = len - 1;
        vector<int> ret;
        while(s < e)
        {
            int m = s + ((e - s) >> 1);
            if(nums[m] < target)
                s = m + 1;
            else
                e = m;
        }
        
        if(nums[s] != target)
            return {-1, -1};
        ret.push_back(s);
        e = len;
        
        while(s < e)
        {
            int m = s + ((e - s) >> 1);
            if(nums[m] <= target)
                s = m + 1;
            else
                e = m;
        }
        ret.push_back(e - 1);
        
        return ret;
        
    }
};