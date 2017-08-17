class Solution {
public:
    void dfs(int b, int k, int n)
    {
        if (n < 0) {
            return;
        } else if (n == 0) {
            if(k == 0)
                ret.push_back(now);
            return;
        } else if (k == 0)
            return;
        
        //n > 0 && k > 0
        for (int i = b; i <= 9; i++) {
            now.push_back(i);
            dfs(i + 1, k - 1, n - i);
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(1, k, n);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
};