//每一个字符，都可以选择要不要。
//要的话，把count里面的数字和本字符打上去，然后count变成0，指针加一
//不要的话，count+1，指针加一
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        dfs(word, "", 0, 0);
        return ret;
    }
private:
    vector<string> ret;
    void dfs(string &word, string now, int pos, int count) {
        if(pos == word.size()) {
            if(count > 0)
                now += to_string(count);
            ret.push_back(now);
            return;
        } else {
            dfs(word, now, pos + 1, count + 1);
            dfs(word, now + (count > 0 ? to_string(count) : "") + word[pos], pos + 1, 0);
        }
    }
};