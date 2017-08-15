//DFS，这次的方法不一样，每一次都要从头开始。
class Solution {
public:

    void dfs(vector<int> &nums, int counts) {
        int len = nums.size();
        if(counts == len) {
            ret.push_back(now);
            return;
        }
        for(int i = 0; i < len; i++)
        {
            if(!check.count(i))
            {
                check.insert(i);
                now.push_back(nums[i]);        
                dfs(nums, counts + 1);
                now.pop_back();
                check.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
    unordered_set<int> check;
};