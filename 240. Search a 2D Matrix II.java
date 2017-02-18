//在一个二维矩阵中，每一行是递增的，每一列也是递增的，问怎么搜索一个数字？
//面试题trick：从右上角开始搜索，如果target比这个数大，则不可能在这一行；如果target比这个数小，则不可能在这一列。这样每次搜索起点都在右上角，一定可以搜索到这个数，O(m + n)。
    public boolean searchMatrix(int[][] matrix, int target)
    {
        int m = matrix.length;
        if(m == 0)
            return false;
        int n = matrix[0].length;
        if(n == 0)
            return false;
        int r = 0;
        int c = n - 1;
        while(r >= 0 && r < m && c >= 0 && c < n)
        {
            if(target == matrix[r][c])
                return true;
            else if(target > matrix[r][c])
                r++;
            else
                c--;
        }
        return false;
    }