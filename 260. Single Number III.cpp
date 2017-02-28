//找到最后一位不相等的bit，在原数组中寻找即可
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xx = 0;
        for(auto i : nums)
            xx ^= i;
        int lastone = xx & (-xx);
        int x = 0;
        int y = 0;
        for(auto i : nums)
        {
            if(lastone & i)
                x ^= i;
            else
                y ^= i;
        }
        return {x, y};
    }
};