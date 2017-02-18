class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int len = nums.size();
        k %= len;
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
    }
};