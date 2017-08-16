//BFS，找到一个单词就删除一个
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wl = beginWord.size();
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> dict(wordList.begin(), wordList.end());
        int step = 1;
        while(!que.empty()) {
            int len = que.size();
            for(int i = 0; i < len; i++) {
                string now = que.front();
                que.pop();          
                if(endWord == now)
                    return step;
                for(int j = 0; j < wl; j++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string changed = now;
                        changed[j] = c;
                        if(dict.count(changed)) {
                            dict.erase(changed);
                            que.push(changed);
                        }
                    }
                }
            }
            ++step;
        }
        return 0;
    }
};