//测试样例有误。
//应该是先找到边，然后拓扑排序即可
class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        map<char, set<char>> suc, pre;
        set<char> chars;
        string s;
        for (string t : words)
        {
            chars.insert(t.begin(), t.end());
            int lenmin = min(s.size(), t.size());
            for (int i = 0; i < lenmin; i++) 
            {
                char a = s[i];
                char b = t[i];
                if (a != b) 
                {
                    suc[a].insert(b);
                    pre[b].insert(a);
                    break;
                }
            }
            s = t;
        }
        if(!pre.size())
            return "";
        set<char> free = chars;
        string order;
        while (free.size())//free里面就是所有的0入度点
        {
            char a = *begin(free);
            free.erase(a);
            order += a;
            for (char b : suc[a]) 
            {
                pre[b].erase(a);
                if (pre[b].empty())
                    free.insert(b);
            }
        }
        return order.size() == chars.size() ? order : "";
    }
};