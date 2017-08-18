//树状数组的第二种用法，用作计数。
//每次找到一个数的时候，把这个数位置上加1，代表这里存在更小的数。
//这样当我找到数组中后面一个数的时候，我返回的是之前的加和，那么就能够找到个数了。
//这种方法比直接的hashtable快，logn一次，总共nlogn。
//重要的是数组值不能为负，所以一定要全部变成正数。

class Solution {
public:
    #define MAXI 12010
    int BIT[MAXI];
    void makepositive(vector<int> &nums) {
        int len = nums.size();
        int min = 1;
        for(int i = 0; i < len; i++)
            min = (min < nums[i] ? min : nums[i]);
        if(min <= 0)
            for(int i = 0; i < len; i++)
                nums[i] += (-min + 1);
    }
    int get(int idx) {
        int ret = 0;
        for (int i = idx; i > 0; i -= (i & (-i))) {
            ret += BIT[i];
        }
        return ret;
    }
    
    void inc(int idx) {
        for (int i = idx; i < MAXI; i += (i & (-i))) {
            BIT[i]++;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, 0);
        makepositive(nums);
        for (int i = len - 1; i >= 0; i--) {
            ret[i] = get(nums[i]);
            inc(nums[i] + 1);
        }
        return ret;
    }
};