//Trie + DFS
class Trie
{
public:
    Trie *next[26];
    bool isend;
    Trie()
    {
        isend = false;
        memset(next, 0, sizeof(next));
    }
};

class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>>& board, 
             Trie *node, vector<string>& ret, vector<string>& words, vector<vector<char>>& hash, string now) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
           node->next[board[i][j] - 'a'] == NULL || hash[i][j] == 0)
            return;
        node = node->next[board[i][j] - 'a'];
        now += board[i][j];
        if (node->isend && !used.count(now)) {
            ret.push_back(now);
            used.insert(now);
        }
        hash[i][j] = 0;
        dfs(i + 1, j, board, node, ret, words, hash, now);
        dfs(i - 1, j, board, node, ret, words, hash, now);
        dfs(i, j + 1, board, node, ret, words, hash, now);
        dfs(i, j - 1, board, node, ret, words, hash, now);
        hash[i][j] = board[i][j];
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        int row = board.size();
        int col = board[0].size();
        int len = words.size();
        Trie *root = new Trie();
        for (int i = 0; i < len; i++) {
            Trie *node = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (node->next[words[i][j] - 'a']) {
                    node = node->next[words[i][j] - 'a'];
                } else {
                    Trie *temp = new Trie();
                    node->next[words[i][j] - 'a']= temp;
                    node = temp;
                }         
            }
            node->isend = true;
        }
    
        vector<vector<char>> hash(board);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                dfs(i, j, board, root, ret, words, hash, "");
        return ret;
    }
private:
    unordered_set<string> used;
};