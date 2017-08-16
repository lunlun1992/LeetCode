//running minium
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = INT_MIN;
        int mini = INT_MAX;
        for (auto p : prices) {
            ret = max(ret, p - mini);
            mini = min(mini, p);
        }
        return ret < 0 ? 0 : ret;
    }
};