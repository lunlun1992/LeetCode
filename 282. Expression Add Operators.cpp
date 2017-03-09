class Solution {
public:
    vector<string> addOperators(string num, int target) 
    {
        int len = num.size();
        if(!len)
            return {};
        dfs(num, 0, len, target, 0, 0, "");
        return ret;
    }
private:
    vector<string> ret;
    void dfs(string &num, int idx, int end, int t, int64_t cur, int64_t diff, string now)
    {
        if(idx == end && t == cur)
        {
            ret.push_back(now);
            return;
        }
        for(int i = idx; i < end; i++)
        {
            if(i != idx && num[idx] == '0')
                continue;
            string ss = num.substr(idx, i + 1 - idx);
            istringstream is(ss);//新方法，一定要学习
            int64_t nn;
            is >> nn;
            if(now.empty())
                dfs(num, i + 1, end, t, nn, nn, ss);
            else
            {
                dfs(num, i + 1, end, t, cur + nn, nn, now + "+" + ss);
                dfs(num, i + 1, end, t, cur - nn, -nn, now + "-" + ss);
                dfs(num, i + 1, end, t, cur - diff + nn * diff, nn * diff, now + "*" + ss);
            }
        }
    }
    
};