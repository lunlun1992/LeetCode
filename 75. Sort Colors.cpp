//三个指针，start左边是0，e的右边是2，b扫过整个数组进行划分
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int len = nums.size();
        int e = len - 1;
        int b = 0;
        int start = -1;
        
        while(b <= e)
        {
            if(nums[e] == 2)
                e--;
            else if(nums[b] == 0)
            {
                nums[b] = nums[++start];
                nums[start] = 0;
                b++;
            }
            else if(nums[b] == 1)
                b++;
            else if(nums[b] == 2)
            {
                nums[b] = nums[e];
                nums[e] = 2;
            }
        }
    }
};