//分行列以及小格子分别设置一个hash表，判定数字是否重复。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(digits[0][i][board[i][j] - '0'])
                    return false;
                else
                    digits[0][i][board[i][j] - '0'] = true;
                
                if(digits[1][j][board[i][j] - '0'])
                    return false;
                else
                    digits[1][j][board[i][j] - '0'] = true;
                
                int idx = i / 3 * 3 + j / 3;
                if(digits[2][idx][board[i][j] - '0'])
                    return false;
                else
                    digits[2][idx][board[i][j] - '0'] = true;
            }
        }
        return true;
    }
private:
    bool digits[3][9][10];
};