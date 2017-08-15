class Solution {
public:
//两次bsearch，第一次找左边界，第二次找右边界。
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int len = nums.size();
        int s = 0;
        int e = len - 1;
        while(s <= e) {
            int m = s + ((e - s) >> 1);
            if(nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        } 
        int save = s;
        
        s = 0;
        e = len - 1;
        while (s <= e) {
            int m = s + ((e - s) >> 1);
            if(nums[m] <= target)
                s = m + 1;
            else
                e = m - 1;
        }
        if (s == save)
            return {-1, -1};
        else
            return {save, s - 1};
    }
};

//二分法模板，现在全部用等于。
//下面是upper_bound，最后s落下的地方就是结果。
s = 0;
e = len - 1;
while (s <= e) {
    int m = s + ((e - s) >> 1);
    if(nums[m] <= target)
        s = m + 1;
    else
        e = m - 1;
}