class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) 
    {
        this->n = n;
        nrows.first.assign(n, 0);
        nrows.second.assign(n, 0);
        ncols.first.assign(n, 0);
        ncols.second.assign(n, 0);
        diag_45.first = 0;
        diag_45.second = 0;
        diag_135.first = 0;
        diag_135.second = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) 
    {
        if(player == 1)
        {
            nrows.first[row]++;
            ncols.first[col]++;
            if(row == col)
                diag_45.first++;
            if(row + col == n - 1)
                diag_135.first++;
            if(nrows.first[row] == n || ncols.first[col] == n || diag_45.first == n || diag_135.first == n)
                return 1;
        }
        else
        {
            nrows.second[row]++;
            ncols.second[col]++;
            if(row == col)
                diag_45.second++;
            if(row + col == n - 1)
                diag_135.second++;
            if(nrows.second[row] == n || ncols.second[col] == n || diag_45.second == n || diag_135.second == n)
                return 2;
        }
        return 0;
    }
private:
    int n;
    pair<vector<int>, vector<int>> nrows;
    pair<vector<int>, vector<int>> ncols;
    pair<int, int> diag_45;
    pair<int, int> diag_135;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */