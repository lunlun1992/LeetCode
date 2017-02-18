class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<int> numinwindow;
        int len = nums.size();
        if(k == 0 || len <= 1 || t < 0)
            return false;
        for(int i = 0; i < len; i++)
        {
            if(numinwindow.size() > k)
                numinwindow.erase(nums[i - k - 1]);
            auto it = numinwindow.lower_bound(nums[i] - t);
            if(it != numinwindow.end() && abs(*it - nums[i]) <= t)
                return true;
            numinwindow.insert(nums[i]);
        }
        return false;
    }
};