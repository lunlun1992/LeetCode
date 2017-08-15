//向hashmap里面放数，直到找到为止，输出这两个index。
//注意这样可以避免重复的数字
//{}初始化不失为一种好的方法。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};