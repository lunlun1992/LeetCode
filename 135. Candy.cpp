//从前往后，找上升阶梯，每一个递加一
//从后往前，再找上升，每一个递加一
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int len = ratings.size();
        if(len <= 1)
            return len;
        vector<int> ret(len, 1);
        
        for(int i = 1; i < len; i++)
            if(ratings[i] > ratings[i - 1])
                ret[i] = ret[i - 1] + 1;
        for(int i = len - 1; i > 0; i--)
            if(ratings[i] < ratings[i - 1])
                ret[i - 1] = max(ret[i - 1], ret[i] + 1);
        int ans = 0;
        for(int i = 0; i < len; i++)
            ans += ret[i];
        return ans;
    }
};