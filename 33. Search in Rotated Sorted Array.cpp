//画图可以解题。
//先看target和mid的大小
//然后看mid在哪一边
//然后判定target在mid的哪一边
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int len = nums.size();
        if(len == 0)
            return -1;
        int s = 0;
        int e = len - 1;
        while(s < e)
        {
            int m = s + ((e - s) >> 1);
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
            {
                if(nums[m] > nums[e])
                    s = m + 1;
                else if(target > nums[e])
                    e = m;
                else
                    s = m + 1;
            }
            else
            {
                if(nums[m] < nums[e])
                    e = m;
                else if(target > nums[e])
                    e = m;
                else
                    s = m + 1;
            }
        }
        if(nums[s] != target)
            return -1;
        else
            return s;
        
    }
};