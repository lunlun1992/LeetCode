//先定义一个target，在target后面找。
//找的方法是双指针，因为已经对数组进行过排序，所以肯定不会错过任何一个相等的组合。
//在找的同时记得去重。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int len = nums.size();
        int target = 0;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++)
        {
            if(i != 0 && target == -nums[i])
                continue;
            target = -nums[i];
            
            int b = i + 1;
            int e = len - 1;
            while(b < e)
            {
                int sum = nums[b] + nums[e];
                if(sum < target)
                    b++;
                else if(sum > target)
                    e--;
                else
                {
                    ret.push_back({nums[i], nums[b], nums[e]});
                    
                    int ori = nums[b];
                    while(b < e && ori == nums[b])
                        b++;
                    ori = nums[e];
                    while(b < e && ori == nums[e])
                        e--;
                }
            }
        }
        
        return ret;
        
    }
};