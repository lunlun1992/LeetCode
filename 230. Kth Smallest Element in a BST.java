//分治法，先统计左子树的节点数，确定在哪里。然后接着递归搜索，有点像select算法。
//无论如何，先写出来再说，不要犹豫会不会更好。
public static int dfs(TreeNode node)
{
    if(null == node)
        return 0;
    else
        return dfs(node.left) + dfs(node.right) + 1;
}
public static int kthSmallest(TreeNode root, int k)
{
    if(null == root)
        return 0;
    int nleft = dfs(root.left);
    if(nleft + 1 == k)
        return root.val;
    else if(nleft + 1 < k)
        return kthSmallest(root.right, k - nleft - 1);
    else
        return kthSmallest(root.left, k);
}