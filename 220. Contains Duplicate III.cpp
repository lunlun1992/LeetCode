class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<int64_t> ms;
        int len = nums.size();
        if(k == 0 || len <= 1 || t < 0)
            return false;
        for(int i = 0; i < len; i++)
        {
            if(i - k - 1 >= 0)
                ms.erase(nums[i - k - 1]);
            auto it = ms.lower_bound((int64_t)nums[i] - t);//nums[i] - nums[j] <= t        
            if(it != ms.end() && *it - nums[i] <= t)//nums[j] - nums[i] <= t
                return true;
            ms.insert((int64_t)nums[i]);
        }
        return false;
    }
};