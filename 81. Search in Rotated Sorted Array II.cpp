//跟之前的逻辑完全一样，只加入了一个条件
//当e和m位置上的数字相等的时候，e--，这样也会缩小范围。
class Solution {
public:
    bool search(vector<int> &nums, int target) 
    {
        int len = nums.size();
        if(len == 0)
            return false;
        int b = 0;
        int e = len - 1;

        while(b < e) {
            int m = b + (e - b) / 2;
            if (nums[m] == target)
                return true;
            if (nums[m] > nums[e]) {
                if (nums[m] > target && nums[b] <= target)
                    e = m;
                else 
                    b = m + 1;
            } else if (nums[m] < nums[e]) {
                if (nums[m] < target && nums[e] >= target)
                    b = m + 1;
                else 
                    e = m;
            } else {
                e--;            //这里是关键。
            }
              
        }
        return nums[b] == target ? true : false;
    }
};