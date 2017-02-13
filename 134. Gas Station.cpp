//主要的思路是：如果油可以剩下，则肯定可以走玩一圈。
//遍历的中途如果发现油空了，就从下一个节点开始作为起点
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        if(gas.empty())
            return -1;
        int sum = gas[0] - cost[0];
        int len = gas.size();
        int start = 0;
        int total = sum;
        for(int i = 1; i < len; i++)
        {
            total += gas[i] - cost[i];
            if(sum < 0)
            {
                start = i;
                sum = gas[i] - cost[i];
            }
            else
                sum += gas[i] - cost[i];
        }
        return total < 0 ? -1 : start;
    }
};