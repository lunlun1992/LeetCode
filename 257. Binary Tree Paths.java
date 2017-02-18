//找到所有树上的路径，采用深度优先的方法，没有使用栈来模拟，因为递归的方法可以免去改变String在父亲节点的值。  
  public static ArrayList<String> arr;
    public static void tree(TreeNode node, String s)
    {
        if(node.left == null && node.right == null)
        {
            arr.add(new String(s + node.val));
        }
        else if(node.left == null)
        {
            tree(node.right, new String(s + node.val + "->"));
        }
        else if(node.right == null)
        {
            tree(node.left, new String(s + node.val + "->"));
        }
        else
        {
            tree(node.left, new String(s + node.val + "->"));
            tree(node.right, new String(s + node.val + "->"));
        }
    }
   
    public List<String> binaryTreePaths(TreeNode root)
    {
        arr = new ArrayList<String>();
        StringBuffer sb = new StringBuffer();
        if(null == root)
            return arr;
        tree(root, "");
        return arr;
    }