class Solution {
public:
    bool dfs(int x, int y, int row, int col, vector<vector<char>>& board, string word, int wl, int depth, vector<vector<bool>>& visit)
    {
        if(depth == wl)
            return true;
        if(x < 0 || x == row || y < 0 || y == col || visit[x][y] || word[depth] != board[x][y])
            return false;
        bool ret = false;
        visit[x][y] = true;
        ret =  dfs(x + 1, y, row, col, board, word, wl, depth + 1, visit)
            || dfs(x, y + 1, row, col, board, word, wl, depth + 1, visit)
            || dfs(x - 1, y, row, col, board, word, wl, depth + 1, visit) 
            || dfs(x, y - 1, row, col, board, word, wl, depth + 1, visit);
        visit[x][y] = false;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        int row = board.size();
        if(!row)
            return false;
        int col = board[0].size();
        int wl = word.size();
        
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(dfs(i, j, row, col, board, word, wl, 0, visit))
                    return true;
        return false;
    }
};