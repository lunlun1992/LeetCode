//这题是一道BFS，每次删除一个括号，然后判断是否合理，放入队列进行判断。
//由于需要找到最小的修改，于是可以这样，找到合理修改之后直接不往更深处搜索了。
//更快。
class Solution {
public:
    vector<string> ret;
    vector<string> removeInvalidParentheses(string s)
    {
        if(s.size() <= 0)
        {
            ret.push_back("");
            return ret;
        }
        unordered_map<string, bool> m;
        queue<string> que;
        bool bFoundMinAlter = false;
        que.push(s);
        m[s] = true;

        while(!que.empty())
        {
            string str = que.front();
            que.pop();
            if(IsValid(str))
            {
                ret.push_back(str);
                bFoundMinAlter = true;
            }
            if(bFoundMinAlter)
                continue;
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == '(' || str[i] == ')')
                {
                    string temp = str;
                    string cat = temp.erase(i, 1);
                    if(m.find(cat) == m.end())
                    {
                        m[cat] = true;
                        que.push(cat);
                    }
                }
            }

        }
        return ret;
    }

    bool IsValid(string s)
    {
        int leftcount = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                leftcount++;
            else if(s[i] == ')')
                leftcount--;
            if(leftcount < 0)
                return false;
        }

        return leftcount != 0 ? false : true;
    }
};