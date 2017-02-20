//大模拟题，主要是怎么表示上一个状态的值。
//因为是int，所以投机取巧了一下。
public class Solution
{
    static int m, n;
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    static int adj(int i, int j, int[][] board)
    {
        int ret = 0;
        for(int k = 0; k < 8; k++)
        {
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx >= 0 && xx < m && yy >= 0 && yy < n && (board[xx][yy] == 10 || board[xx][yy] == 1))
            {
                ret++;
            }
        }
        return ret;
    }
    public void gameOfLife(int[][] board)
    {
        m = board.length;
        if(0 == m)
            return;
        n = board[0].length;
        if(0 == n)
            return;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int num = adj(i, j, board);
                if(board[i][j] == 0 && num == 3)
                {
                    board[i][j] = 101;
                }
                else if(board[i][j] == 1 && (num < 2 || num > 3))
                {
                    board[i][j] = 10;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] %= 2;
            }
        }
        return;
    }
}
