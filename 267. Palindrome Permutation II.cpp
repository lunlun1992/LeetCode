class Solution {
public:
    vector<string> generatePalindromes(string s)
    {
        int len = s.size();
        int odd = 0;
        char oddchar = 0;
        for(int i = 0; i < len; i++)
            m[s[i]]++;
        for(auto it : m)
        {
            if(it.second % 2)
            {
                odd++;
                oddchar = it.first;
            }
        }
        if(!len || odd > 1)
            return {};
        if(odd)
        {
            now.push_back(oddchar);
            m[oddchar]--;
            len--;
        }
        dfs(len);
        return ret;
    }
private:
    unordered_map<char, int> m;
    vector<string> ret;
    string now;
    void dfs(int remain)
    {
        if(remain == 0)
        {
            ret.push_back(now);
            return;
        }
        string now_bak = now;
        for(auto it : m)
        {
            if(it.second)
            {
                now = it.first + now + it.first;
                m[it.first] -= 2;
                dfs(remain - 2);
                m[it.first] += 2;
                now = now_bak;
            }
        }
    }
};