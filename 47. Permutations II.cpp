class Solution {
public:
    void dfs(vector<int> &nums, int counts) {
        int len = nums.size();
        if(counts == len) {
            ret.push_back(now);
            return;
        }
        for(int i = 0; i < len; i++) {
            if (i > 0 && nums[i - 1] == nums[i] && !check.count(i - 1))//和标准的去重不一样，加一个条件，也就是上一层已经查询过相同的数字了。
                continue;                                              //这一层的紧接着下一个相同数字是可以查询的，但是再下一个就不行了。
            if(!check.count(i)) {
                check.insert(i);
                now.push_back(nums[i]);        
                dfs(nums, counts + 1);
                now.pop_back();
                check.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
    unordered_set<int> check;
};