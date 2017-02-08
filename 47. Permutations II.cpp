class Solution {
public:

    void dfs(vector<int> &nums, int counts)
    {
        int len = nums.size();
        if(counts == len)
        {
            ret.push_back(now);
            return;
        }
        
        for(int i = 0; i < len; i++)
        {
            if(!check.count(i))
            {
                check.insert(i);
                now.push_back(nums[i]);
                
                dfs(nums, counts + 1);
                
                now.pop_back();
                check.erase(i);
                int j = i;
                while(j < len && nums[j] == nums[i])
                    j++;
                i = j - 1;//在回溯的时候去重，如果本数被DFS过了，并且已经回溯，则后面的相同数字不再考虑。
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> now;
    unordered_set<int> check;
};