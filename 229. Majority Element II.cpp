//芯片淘汰法，发现不一样的就一起扔，发现一样的就加1.
//顺序芯片淘汰法虽然时间复杂度高，但是简单。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 1)   
            return nums;
        vector<int> ret;
        int b0, b1;
        int c0 = 0;
        int c1 = 0;
        for(int i = 0; i < len; i++)
        {
            if(b1 != nums[i] && c0 == 0)
            {
                b0 = nums[i];
                c0++;
            }
            else if(b0 != nums[i] && c1 == 0)
            {
                b1 = nums[i];
                c1++;
            }
            else
            {
                if(nums[i] == b0)
                    c0++;
                else if(nums[i] == b1)
                    c1++;
                else
                {
                    c0--;
                    c1--;
                }
            }
        }
        if(c0 > 0)
        {
            int count = 0;
            for(int i = 0; i < len; i++)
                if(b0 == nums[i])
                    count++;
            if(count > len / 3)
                ret.push_back(b0);
        }
        if(c1 > 0)
        {
            int count = 0;
            for(int i = 0; i < len; i++)
                if(b1 == nums[i])
                    count++;
            if(count > len / 3)
                ret.push_back(b1);
        }
        return ret;
    }
};