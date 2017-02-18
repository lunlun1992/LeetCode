//向hashmap里面放数，直到找到为止，输出这两个index。
//注意这样可以避免重复的数字
//{}初始化不失为一种好的方法。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int another = target - nums[i];
            if(s.count(another))
                return {s[another], i};
            s[nums[i]] = i;
        }
        return ret;
    }
private:
    unordered_map<int, int> s;
};