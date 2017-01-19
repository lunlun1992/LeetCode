//按照之前的2sum和3sum方法来做。
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len - 3; i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int t = target - nums[i];
            for(int j = i + 1; j < len - 2; j++)
            {
                if(j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int tt = t - nums[j];
                int b = j + 1;
                int e = len - 1;
                while(b < e)
                {
                    int sum = nums[b] + nums[e];
                    if(sum < tt)
                        b++;
                    else if(sum > tt)
                        e--;
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[b], nums[e]});
                        int ori = nums[b];
                        while(b < e && nums[b] == ori)
                            b++;
                        ori = nums[e];
                        while(b < e && nums[e] == ori)
                            e--;
                    }
                }
            }
        }
        return ret;
    }
};