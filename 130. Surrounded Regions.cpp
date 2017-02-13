//在最外面一圈，找到所有的○，然后DFS把相邻的○都变成*，最后遍历所有点把○变成X，把*变成○。
//关键是如何做标记，可以在原空间上面做标记
class Solution {
public:
    int nRows;
    int nCols;
    typedef pair<int, int> P;
    void dfs(int i, int j, vector<vector<char>>& b)
    {
        //printf("%d %d\n", i, j);
        stack<P> st;
        st.push(P(i, j));
        while(!st.empty())
        {
            P p = st.top();
            st.pop();
            int f = p.first;
            int s = p.second;
            if(f < 0 || f == nRows || s < 0 || s == nCols || b[f][s] == 'X' || b[f][s] == '*')
                continue;
            b[f][s] = '*';
            st.push(P(f - 1, s));
            st.push(P(f + 1, s));
            st.push(P(f, s - 1));
            st.push(P(f, s + 1));
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        nRows = board.size();
        if(nRows == 0)
            return;
        nCols = board[0].size();
        if(nCols == 0)
            return;
        
        for(int i = 0; i < nCols; i++)
            if(board[0][i] == 'O')
                dfs(0, i, board);
        for(int i = 0; i < nCols; i++)
            if(board[nRows - 1][i] == 'O')
                dfs(nRows - 1, i, board);
        for(int i = 0; i < nRows; i++)
            if(board[i][0] == 'O')
                dfs(i, 0, board);
        for(int i = 0; i < nRows; i++)
            if(board[i][nCols - 1] == 'O')
                dfs(i, nCols - 1, board);
        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '*')
                    board[i][j] = 'O';
    }
};