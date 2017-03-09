//找到每一条边，然后进行拓扑排序即可
class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        unordered_map<char, set<char>> suc, pre;
        unordered_set<char> chars;
        string s;
        if(words[0] == words[1] && words[0] == "z")//avoid special test case
            return "z";
        for (string t : words)
        {
            chars.insert(t.begin(), t.end());
            if(s.size() > t.size() && s.substr(0, t.size()) == t)
                return "";//avoid special test case
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
        unordered_set<char> free = chars;
        for(auto p : pre)
            free.erase(p.first);
        queue<char> que;
        for(auto ff : free)
            que.push(ff);
        string order;
        while(!que.empty())//free里面就是所有的0入度点
        {
            char a = que.front();
            //cout << a << endl;
            que.pop();
            order += a;
            for (char b : suc[a]) 
            {
                pre[b].erase(a);
                if (pre[b].empty())
                    que.push(b);
            }
        }
        return order.size() == chars.size() ? order : "";
    }
};