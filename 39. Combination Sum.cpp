//DFS，方法是首先判定本数字行不行
//然后判定不选择本数字，选择下一个数字行不行
//这样可以遍历整棵树
class Solution {
public:

    void dfs(vector<int>& nums, int idx, int t)
    {
        if(t == 0)
        {
            ret.push_back(now);
            return;
        }
        else if(t < 0 || idx == nums.size())
            return;
        
        now.push_back(nums[idx]);
        dfs(nums, idx, t - nums[idx]);
        now.pop_back();
        
        dfs(nums, idx + 1, t);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dfs(candidates, 0, target);
        return ret;
    }
    
private:
    vector<vector<int>> ret;
    vector<int> now;
};