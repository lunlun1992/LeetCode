//先定义一个target，在target后面找。
//找的方法是双指针，因为已经对数组进行过排序，所以肯定不会错过任何一个相等的组合。
//在找的同时记得去重。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        int target = 0;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++) {
            if(i != 0 && target == -nums[i])
                continue;
            target = -nums[i];         
            int b = i + 1;
            int e = len - 1;
            while (b < e) {
                if(nums[b] + nums[e] == target) {
                    ret.push_back({nums[i], nums[b], nums[e]});
                    int ori = nums[b];
                    while (b < e && nums[b] == ori) b++;
                    ori = nums[e];
                    while (b < e && nums[e] == ori) e--;
                } else if(nums[b] + nums[e] < target) {
                    b++;
                } else {
                    e--;
                }
            }
        }
        return ret;   
    }
};