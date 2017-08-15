//DFS，方法是首先判定本数字行不行
//然后判定不选择本数字，选择下一个数字行不行
//这样可以遍历整棵树
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
            now.push_back(can[i]);
            dfs(can, i, t - can[i], now, ret);
            now.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        dfs(candidates, 0, target, now, ret);
        return ret;
    }
};