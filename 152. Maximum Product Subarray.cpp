//有可能负负得正
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> dpmax(len, 0); 
        vector<int> dpmin(len, 0); 

        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < len; i++)
        {
            dpmax[i] = max(dpmin[i - 1] * nums[i], dpmax[i - 1] * nums[i]);
            dpmax[i] = max(dpmax[i], nums[i]);
            dpmin[i] = min(dpmin[i - 1] * nums[i], dpmax[i - 1] * nums[i]);
            dpmin[i] = min(dpmin[i], nums[i]);
            maxi = max(maxi, dpmax[i]);
        }
        return maxi;
    }
};