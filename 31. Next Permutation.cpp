class Solution {
public:

    void change(vector<int> &nums, int u, int v)
    {
        for(; u < v; u++, v--)
        {
            int temp = nums[u];
            nums[u] = nums[v];
            nums[v] = temp;
        }
    }
    void nextPermutation(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 2)
            return;
        
        //1、从尾往头找第一个j处于峰值，后面的都小，前面的也小。
        int j = len - 1;
        while(j > 0 && nums[j] <= nums[j - 1])
            j--;
        if(j == 0)
        {
            change(nums, 0, len - 1);
            return;
        }
        
        //2、把j-1位置上的数和[j,len-1]上最后一个比nums[j-1]大但是最接近nums[j-1]的数交换位置
        int val = nums[j - 1];
        int mini = INT_MAX;
        int idx = 0;
        for(int i = j; i < len; i++)
        {
            if(nums[i] > val)
            {
                int diff = nums[i] - val;
                if(diff <= mini)
                {
                    mini = diff;
                    idx = i;
                }
            }
        }
        nums[j - 1] = nums[idx];
        nums[idx] = val;
        
        //3、反转[j,len-1]
        change(nums, j, len - 1);
    }
};