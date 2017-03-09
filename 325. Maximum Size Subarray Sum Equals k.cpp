//和Two Sum一样，采用了unordered_map的方法
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        int len = nums.size();
        if(!len)
            return 0;
        int ret = 0;
        unordered_map<int, int> m;
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            sum += nums[i];
            if(sum == k)
                ret = max(ret, i + 1);
            else if(m.count(sum - k))
                ret = max(ret, i - m[sum - k]);
            if(!m.count(sum))
                m[sum] = i;
        }
        return ret;
    }
};