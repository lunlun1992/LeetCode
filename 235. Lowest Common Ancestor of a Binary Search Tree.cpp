//在二叉搜索树上找到同一个祖先，简单的方法就是利用性质。
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        TreeNode big, small;
        if(null == p || null == q)
            return null;
        if(p.val == q.val)
            return p;
        else if(p.val > q.val)
        {
            big = p;
            small = q;
        }
        else
        {
            big = q;
            small = p;
        }
        TreeNode t = root;
        while(t != null)
        {
            if(t.val > big.val && t.val > small.val)
            {
                t = t.left;
                continue;
            }
            else if(t.val < big.val && t.val < small.val)
            {
                t = t.right;
                continue;
            }
            else
            {
                return t;
            }
        }
        return t;
    }