//简单的dfs题目，注意标记数组以及终止条件即可。
public class Solution {
    static boolean[][] flag;
    static int row;
    static int col;
    static char[][] g;
    static boolean dfs(int i, int j) {
        if(i >= row || i < 0 || j >= col || j < 0 || flag[i][j] || g[i][j] == '0')
            return false;
        flag[i][j] = true;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
        return true;
    }
    public int numIslands(char[][] grid) {
        row = grid.length;
        if(row == 0)
            return 0;
        col = grid[0].length;
        if(col == 0)
            return 0;
        g = grid;
        flag = new boolean[row][col];
        int ret = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(dfs(i, j))
                    ret++;
        return ret;
    }
}