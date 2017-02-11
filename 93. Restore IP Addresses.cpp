//简单的DFS，重点是如果这一位是0，要特殊处理。
class Solution {
public:
    void dfs(string s, string cur, int isegs, int curpos)
    {
        if(isegs == 0)
        {
            if(s.size() == curpos)
                ret.push_back(cur);
            return;
        }
        if(curpos >= s.size())
            return;
        string bak = cur;
        
        if(s[curpos] == '0')
        {
            if(isegs == 4)
                cur += '0';
            else
                cur += ".0";
            dfs(s, cur, isegs - 1, curpos + 1);
            cur = bak;
        }
        else
        {
            for(int i = 1; i <= 3; i++)
            {
                string snum = s.substr(curpos, i);
                int num = atoi(snum.c_str());
                if(num <= 255)
                {
                    if(isegs == 4)
                        cur += snum;
                    else
                        cur += "." + snum;
                    dfs(s, cur, isegs - 1, curpos + i);
                    cur = bak;
                }
            }
        }
            
    }
    vector<string> restoreIpAddresses(string s)
    {
        if(s.empty())
            return ret;
        string cur = "";
        dfs(s, cur, 4, 0);
        return ret;
    }
private:
    vector<string> ret;
};