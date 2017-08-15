class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ret = target;
        for(int i = 0; i < len; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) 
                continue;
            int b = i + 1;
            int e = len - 1;
            while(b < e) {
                int sum = nums[b] + nums[e] + nums[i];
                if(sum < target) b++;
                else if(sum > target) e--;
                else return target;
                if(abs(sum - target) < diff) {
                    ret = sum;
                    diff = abs(sum - target);
                }
            }
        }
        return ret;
        
    }
};