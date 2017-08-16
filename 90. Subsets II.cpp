//树上的每一个节点都要遍历
class Solution {
public:
    void dfs(int idx, int len, vector<int> &nums) {
        ret.push_back(now);
        if(idx == len)
            return;
        for(int i = idx; i < len; i++) {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            now.push_back(nums[i]);
            dfs(i + 1, len, nums);
            now.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        dfs(0, len, nums);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};