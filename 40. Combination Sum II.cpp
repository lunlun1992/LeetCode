//和上一题的区别就在去重。这里如何去重？
//首先需要排序
//然后这里的DFS有两个分支，选择本数字和不选择本数字
//当选择了本数字，可以选择任意个后面的相同数字，也不会产生重复
//当不选择本数字，则后面人一个相同的数字都不应该选，否则会产生重复。
class Solution {
public:
    
    void dfs(vector<int>& can, int idx, int t, vector<int>& now, vector<vector<int>>& ret) {
        if (!t) {
            ret.push_back(now);
            return;
        } else if(t < 0) {
            return;
        }
        for(int i = idx; i < can.size(); i++) {
            if (i != idx && can[i] == can[i - 1])
                continue;
            now.push_back(can[i]);
            dfs(can, i + 1, t - can[i], now, ret);
            now.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, now, ret);
        return ret;
    }
};