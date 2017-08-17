class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        
        int len = nums.size();
        int i = 0;
        while(i < len) {
            int j = i;
            while(j + 1 < len && nums[j + 1] == nums[j] + 1)
                j++;
            if(i != j)
                ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            else
                ret.push_back(to_string(nums[i]));
            i = j + 1;
        }
        return ret;
    }
};