//只需要得到上一次最小的两个值，原因是不能涂一样的颜色
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        int len = costs.size();
        if(!len)
            return 0;
        int k = costs[0].size();
        for (int i = 1; i < len; i++) {
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if(costs[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = costs[i - 1][j];
                } else if(costs[i - 1][j] < min2) {
                    min2 = costs[i - 1][j];
                }
            }
            for (int j = 0; j < k; j++)
                costs[i][j] += min1 == costs[i - 1][j] ? min2 : min1;
        }
        int mini = INT_MAX;
        for(int i = 0; i < k; i++)
            mini = min(mini, costs[len - 1][i]);
        return mini;
    }
};