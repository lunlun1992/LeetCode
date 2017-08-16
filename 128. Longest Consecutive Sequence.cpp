//Use hashmap to decrease the time
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> st;
        int ret = 0;
        for (auto n : nums)
            st[n] = false;
        for (auto n : nums) {
            if (!st[n]) {
                st[n] = true;
                int cur = 1;
                int left = n - 1;
                while (st.count(left) && !st[left]) {
                    st[left] = true;
                    ++cur;
                    --left;
                }
                
                int right = n + 1;
                while (st.count(right) && !st[right]) {
                    st[right] = true;
                    ++cur;
                    ++right;
                }
                ret = max(ret, cur);
            }
        }
        return ret;
    }
        
};