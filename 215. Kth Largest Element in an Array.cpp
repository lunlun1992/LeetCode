class Solution {
public:
    int findk(vector<int> &nums, int b, int e, int pos)
    {
        if(b == e)
            return nums[b];
        int pivot = nums[e];
        int i = b - 1;
        for(int j = b; j < e; j++)
            if(nums[j] < pivot)
                swap(nums[j], nums[++i]);
        swap(nums[e], nums[++i]);
        if(i == pos)
            return pivot;
        else if(i > pos)
            return findk(nums, b, i - 1, pos);
        else
            return findk(nums, i + 1, e, pos);
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        int len = nums.size();
        if(!len)
            return 0;
        return findk(nums, 0, len - 1, len - k);
    }
};