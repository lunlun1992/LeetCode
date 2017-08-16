class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int accu = 0;
        int now = 0;
        for (int i = 0; i < gas.size(); i++) {
            accu += gas[i] - cost[i];
            now += gas[i] - cost[i];
            if (now < 0) {
                start = i + 1;
                now = 0;
            }
        }
        return accu < 0 ? -1 : start;
    }
};