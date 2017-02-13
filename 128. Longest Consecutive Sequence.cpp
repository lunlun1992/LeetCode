//hashmap用来判定有没有连续的一段
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int len = nums.size();
        if(len <= 0)
            return 0;
        int ret = 0;
        unordered_map<int, bool> m;
        for(int i = 0; i < len; i++)
            m[nums[i]] = false;
        for(int i = 0; i < len; i++)
        {
            if(!m[nums[i]])
            {
                m[nums[i]] = true;
                int cur = 1;
                int left = nums[i] - 1;
                while(m.count(left) && !m[left] && left >= INT_MIN)
                {
                    m[left] = true;
                    cur++;
                    left--;
                }
            
                int right = nums[i] + 1;
                while(m.count(right) && !m[right] && right <= INT_MAX)
                {
                    m[right] = true;
                    cur++;
                    right++;
                }
                
                ret = (cur > ret ? cur : ret);
            }
        }
        return ret;
    }
};