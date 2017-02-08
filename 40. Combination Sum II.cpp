//和上一题的区别就在去重。这里如何去重？
//首先需要排序
//然后这里的DFS有两个分支，选择本数字和不选择本数字
//当选择了本数字，可以选择任意个后面的相同数字，也不会产生重复
//当不选择本数字，则后面人一个相同的数字都不应该选，否则会产生重复。
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
        dfs(nums, idx + 1, t - nums[idx]);
        now.pop_back();
        
        int j = idx + 1;
        while(j < nums.size() && nums[j] == nums[idx])
            j++;
        dfs(nums, j, t);
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};