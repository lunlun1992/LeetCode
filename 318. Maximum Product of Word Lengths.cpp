class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        
        for (auto w : words) {
            int fp = 0;
            for (auto c : w) {
                fp |= (1 << (c - 'a'));
            }
            if(!mp.count(fp) || mp[fp] < w.size()) {
                mp[fp] = w.size();
            }
        }
        
        int ret = 0;
        for (auto p : mp) {
            for (auto q : mp) {
                if (p.first & q.first)
                    continue;
                ret = max(p.second * q.second, ret);
            }
        }
        return ret;
    }
};