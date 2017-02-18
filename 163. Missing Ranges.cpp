//简单的巡逻问题，注意最后结尾处的upper，还有溢出的问题
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string> ret;
        int len = nums.size();
        int64_t pre = (int64_t)lower;
        for(int i = 0; i < len; i++)
        {
            if(pre < nums[i])
            {
                int e = nums[i] - 1;
                if(pre == e)
                    ret.push_back(to_string(pre));
                else
                    ret.push_back(to_string(pre) + "->" + to_string(e));
            }
            pre = (int64_t)nums[i] + 1;
        }
        if(pre <= upper)
        {
            if(pre == upper)
                ret.push_back(to_string(pre));
            else
                ret.push_back(to_string(pre) + "->" + to_string(upper));
        }
        return ret;
    }
};