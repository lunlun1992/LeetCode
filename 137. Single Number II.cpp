class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int len = nums.size();
        int bits[32] = {0};
        for(int i = 0; i < len; i++)
        {
            int n = nums[i];
            for(int j = 0; j < 32; j++)
            {
                if(n & 1)
                    bits[j]++;
                n >>= 1;
            }
        }
        int ret = 0;
        for(int i = 0; i < 32; i++)
            ret |= (bits[i] % 3) << i;
        return ret;
    }
};