//DFS加上Hash
class Solution {
public:
    bool wordPatternMatch(string pattern, string str)
    {
        int lenp = pattern.size();
        int lens = str.size();
        if(lenp > lens)
            return false;
        return dfs(pattern, 0, lenp, str, 0, lens);
    }
private:
    unordered_map<char, string> mp;
    unordered_set<string> st;
    bool dfs(string &p, int pi, int pe, string &s, int si, int se)
    {
        if(pi == pe && si == se)
            return true;
        else if(pi == pe || si == se)
            return false;
        
        char now = p[pi];
        if(mp.count(now))
        {
            string nowstr = mp[now];
            int lennow = nowstr.size();
            string ins = s.substr(si, lennow);

            if(se - si >= lennow && ins == nowstr)
                return dfs(p, pi + 1, pe, s, si + lennow, se);
            else
                return false;
        }
        else
        {
            for(int i = si; i < se; i++)
            {
                string nowstr = s.substr(si, i - si + 1);
                if(st.count(nowstr))
                    continue;
                mp[now] = nowstr;
                st.insert(nowstr);
                if(dfs(p, pi + 1, pe, s, i + 1, se))
                    return true;
                st.erase(nowstr);
                mp.erase(now);
            }
            return false;
        }
        
    }
};