//DFS。
//首先，需要一个hash数组，并且实施维护
//然后，进行DFS，dfs的时候可以按照任何方向进行，这里我们选择的是光栅扫描的方式。
//
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int idx) {
        if(idx == 81)
            return true;
        int row = idx / 9;
        int col = idx % 9;
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i++) {
                int thisone = row / 3 * 3 + col / 3;
                if (!digits[0][row][i] && !digits[1][col][i] && !digits[2][thisone][i])
                {
                    digits[0][row][i] = true;
                    digits[1][col][i] = true;
                    digits[2][thisone][i] = true;
                    board[row][col] = i + '0';
                    if(dfs(board, idx + 1))
                        return true;
                    board[row][col] = '.';
                    digits[2][thisone][i] = false;                                      
                    digits[1][col][i] = false;
                    digits[0][row][i] = false;
                }
            }
        } else {
            if(dfs(board, idx + 1))
                return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                digits[0][i][board[i][j] - '0'] = true;
                digits[1][j][board[i][j] - '0'] = true;
                int idx = i / 3 * 3 + j / 3;
                digits[2][idx][board[i][j] - '0'] = true;
            }
        }
        dfs(board, 0);
    }
private:
    bool digits[3][9][10];
};