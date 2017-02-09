//递归树上的每一个节点都要放进来。
class Solution {
public:
    void dfs(int idx, int len, vector<int> &nums)
    {
        ret.push_back(now);
        if(idx == len)
            return;
        for(int i = idx; i < len; i++)
        {
            now.push_back(nums[i]);
            dfs(i + 1, len, nums);
            now.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int len = nums.size();
        dfs(0, len, nums);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};