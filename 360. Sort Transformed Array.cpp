//直接二分即可
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        int len = nums.size();
        vector<int> ret(len, 0);
        int i = 0;
        int j = len - 1;
        if(a >= 0)
        {
            int idx = len - 1;
            while(i <= j)
            {
                int cali = cal(nums[i], a, b, c);
                int calj = cal(nums[j], a, b, c);
                if(cali > calj)
                {
                    ret[idx--] = cali;
                    i++;
                }
                else
                {
                    ret[idx--] = calj;
                    j--;
                }
            }
        }
        else
        {
            int idx = 0;
            while(i <= j)
            {
                int cali = cal(nums[i], a, b, c);
                int calj = cal(nums[j], a, b, c);
                if(cali < calj)
                {
                    ret[idx++] = cali;
                    i++;
                }
                else
                {
                    ret[idx++] = calj;
                    j--;
                }
            } 
        }
        return ret;
    }
private:
    inline int cal(int val, int a, int b, int c)
    {
        return a * val * val + b * val + c;
    }
};