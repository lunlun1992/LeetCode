//大致思路是，先BFS找到路径，用一个hashmap存储每一个string的下一跳是什么
//然后最后DFS还原路径
class Solution {
public:

    void dfs(string &b, string &e, unordered_map<string, unordered_set<string>>& m)
    {
        if(b == e)
        {
            ret.push_back(rec);
            return;
        }
        if(!m.count(b))
            return;
        for(auto ss : m[b])
        {
            rec.push_back(ss);
            dfs(ss, e, m);
            rec.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> m;
        unordered_map<string, int> visited;
        queue<string> que;
        que.push(beginWord);
        int wl = beginWord.size();
        if(dict.count(beginWord))
            dict.erase(beginWord);
        if(!dict.count(endWord))
            return {};
        int step = 0;
        while(!que.empty())
        {
            int len = que.size();
            bool earlystop = false;
            for(int i = 0; i < len; i++)
            {
                string now = que.front();
                que.pop();
                for(int j = 0; j < wl; j++)
                {
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        string changed = now;
                        changed[j] = c;
                        if(changed == endWord)
                        {
                            earlystop = true;
                            m[now].insert(changed);
                        }
                        else if(dict.count(changed) && (!visited.count(changed) || visited[changed] == step))
                        {
                            que.push(changed);
                            m[now].insert(changed);
                            visited[changed] = step;
                        }
                    }
                }
            }
            if(earlystop)
                break;
            step++;
        }
        // for(auto ss : m["ted"])
        //     cout << ss << endl;
        rec.push_back(beginWord);
        dfs(beginWord, endWord, m);
        return ret;
    }
private:
    vector<vector<string>> ret;
    vector<string> rec;
};