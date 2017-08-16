class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows)
            return {};
        vector<vector<int>> ret;
        ret.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> &last = ret[i - 1];
            vector<int> now;
            now.push_back(1);
            for(int i = 0; i < last.size() - 1; i++)
                now.push_back(last[i] + last[i + 1]);
            now.push_back(1);
            ret.push_back(now);
        }
        return ret;
    }
};